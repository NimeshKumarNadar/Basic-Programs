#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Structure for a term in the polynomial
struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
};

// Function to create a new term
struct Term *createTerm(int coeff, int exp)
{
    struct Term *term = (struct Term *)malloc(sizeof(struct Term));
    term->coefficient = coeff;
    term->exponent = exp;
    term->next = NULL;
    return term;
}

// Function to add two polynomials
struct Term *addPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;
    struct Term *current = NULL;

    while (poly1 && poly2)
    {
        if (poly1->exponent > poly2->exponent)
        {
            if (result == NULL)
            {
                result = createTerm(poly1->coefficient, poly1->exponent);
                current = result;
            }
            else
            {
                current->next = createTerm(poly1->coefficient, poly1->exponent);
                current = current->next;
            }
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            if (result == NULL)
            {
                result = createTerm(poly2->coefficient, poly2->exponent);
                current = result;
            }
            else
            {
                current->next = createTerm(poly2->coefficient, poly2->exponent);
                current = current->next;
            }
            poly2 = poly2->next;
        }
        else
        {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0)
            {
                if (result == NULL)
                {
                    result = createTerm(sumCoeff, poly1->exponent);
                    current = result;
                }
                else
                {
                    current->next = createTerm(sumCoeff, poly1->exponent);
                    current = current->next;
                }
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add any remaining terms from either polynomial
    while (poly1)
    {
        current->next = createTerm(poly1->coefficient, poly1->exponent);
        current = current->next;
        poly1 = poly1->next;
    }

    while (poly2)
    {
        current->next = createTerm(poly2->coefficient, poly2->exponent);
        current = current->next;
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term *poly)
{
    while (poly)
    {
        printf("(%dx^%d) ", poly->coefficient, poly->exponent);
        if (poly->next)
        {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main()
{
    struct Term *polyP;
    struct Term *polyQ;
    struct Term *sumPoly;
    // Create polynomial P(x)
    polyP = createTerm(5, 4);
    polyP->next = createTerm(2, 3);
    polyP->next->next = createTerm(-2, 2);
    polyP->next->next->next = createTerm(17, 0);

    // Create polynomial Q(x)
    polyQ = createTerm(15, 3);
    polyQ->next = createTerm(6, 2);
    polyQ->next->next = createTerm(-2, 0);

    clrscr();

    printf("P(x): ");
    displayPolynomial(polyP);

    printf("Q(x): ");
    displayPolynomial(polyQ);

    // Add polynomials P(x) and Q(x)
    sumPoly = addPolynomials(polyP, polyQ);

    printf("P(x) + Q(x): ");
    displayPolynomial(sumPoly);

    getch();

    return 0;
}

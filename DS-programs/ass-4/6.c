#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term with the given coefficient and exponent
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to a polynomial
void addTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0");
    } else {
        while (poly != NULL) {
            printf("%d", poly->coefficient);
            if (poly->exponent > 0) {
                printf("x^%d", poly->exponent);
            }
            poly = poly->next;
            if (poly != NULL) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

// Function to add two polynomials and return the result
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                addTerm(&result, sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Append any remaining terms from poly1 and poly2
    while (poly1 != NULL) {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        addTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    // Add terms to the first polynomial (3x^2 + 2x + 1)
    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 2, 1);
    addTerm(&poly1, 1, 0);

    // Add terms to the second polynomial (4x^3 + 1)
    addTerm(&poly2, 4, 3);
    addTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);

    printf("Result (Polynomial 1 + Polynomial 2): ");
    displayPolynomial(result);

    // Free allocated memory (you should traverse and free memory properly in a real application)
    free(poly1);
    free(poly2);
    free(result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product_details {
    char name[20];
    int id;
    int price;
};

void pdInput(struct product_details products[]) {
    for (int i = 0; i < 5; i++) {
        printf("Enter Product name: ");
        fgets(products[i].name, sizeof(products[i].name), stdin);

        // Remove the trailing newline character from the name
        size_t len = strlen(products[i].name);
        if (len > 0 && products[i].name[len - 1] == '\n') {
            products[i].name[len - 1] = '\0';
        } else {
            // Clear the input buffer if needed (newline not present)
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        printf("Enter Product ID: ");
        scanf("%d", &products[i].id);

        // Clear the input buffer after reading the integer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Enter Product size: ");
        scanf("%d", &products[i].price);

        // Clear the input buffer after reading the integer
        while ((c = getchar()) != '\n' && c != EOF);
        puts("-----------------------------###>");
    }
}

// Compare function for sorting by product ID
int compareById(const void *a, const void *b) {
    return ((struct product_details *)a)->id - ((struct product_details *)b)->id;
}

// Binary search function for finding a product by ID
struct product_details *binarySearchById(struct product_details products[], int target, int size) {
    qsort(products, size, sizeof(struct product_details), compareById);

    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (products[mid].id == target) {
            return &products[mid];  // Product found
        } else if (products[mid].id < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return NULL;  // Product not found
}

// Search for a product by ID or name until the user types "exit"
void search_pbyID(struct product_details products[]) {
    char input[20];
    while (1) {
        printf("\nEnter Product ID or name (type 'exit' to stop): ");
        fgets(input, sizeof(input), stdin);

        // Remove the trailing newline character from the input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            break;  // Exit the loop if the user types "exit"
        }

        int targetId = atoi(input);  // Convert input to integer
        struct product_details *result = binarySearchById(products, targetId, 5);

        if (result != NULL) {
            printf("Product found - Name: %s, ID: %d, Size: %d\n", result->name, result->id, result->price);
        } else {
            printf("Product not found.\n");
        }
    }
}

int main() {
    struct product_details products[5];
    pdInput(products);
    search_pbyID(products);
    return 0;
}
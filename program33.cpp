#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_IDENTIFIER_LENGTH 50
#define MAX_TYPE_LENGTH 20

// Define the symbol table entry structure
typedef struct {
    char identifier[MAX_IDENTIFIER_LENGTH];
    char type[MAX_TYPE_LENGTH];
} SymbolTableEntry;

// Define the symbol table structure
typedef struct {
    SymbolTableEntry entries[MAX_SYMBOLS];
    int count;
} SymbolTable;

// Function to insert an entry into the symbol table
void insert(SymbolTable* table, const char* identifier, const char* type) {
    if (table->count < MAX_SYMBOLS) {
        strncpy(table->entries[table->count].identifier, identifier, MAX_IDENTIFIER_LENGTH);
        strncpy(table->entries[table->count].type, type, MAX_TYPE_LENGTH);
        table->count++;
    } else {
        printf("Symbol table is full!\n");
    }
}

// Function to lookup an entry in the symbol table
int lookup(SymbolTable* table, const char* identifier) {
    for (int i = 0; i < table->count; i++) {
        if (strncmp(table->entries[i].identifier, identifier, MAX_IDENTIFIER_LENGTH) == 0) {
            return i; // Return the index of the found identifier
        }
    }
    return -1; // Return -1 if the identifier is not found
}

// Function to display all entries in the symbol table
void display(SymbolTable* table) {
    printf("Symbol Table:\n");
    printf("Identifier\tType\n");
    printf("-------------------------\n");
    for (int i = 0; i < table->count; i++) {
        printf("%s\t\t%s\n", table->entries[i].identifier, table->entries[i].type);
    }
}

int main() {
    SymbolTable table;
    table.count = 0;

    // Insert some entries into the symbol table
    insert(&table, "x", "int");
    insert(&table, "y", "float");
    insert(&table, "z", "char");

    // Lookup an entry in the symbol table
    int index = lookup(&table, "y");
    if (index != -1) {
        printf("Found identifier '%s' of type '%s'\n", table.entries[index].identifier, table.entries[index].type);
    } else {
        printf("Identifier 'y' not found in the symbol table\n");
    }

    // Display the symbol table
    display(&table);

    return 0;
}


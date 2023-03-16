#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char filename[MAX_STRING_LENGTH];
    char input[MAX_STRING_LENGTH];
    char buffer[MAX_STRING_LENGTH];
    char *comment;

    // Chiedi all'utente di inserire il nome del file
    printf("Inserisci il nome del file: ");
    scanf("%s", filename);

    // Chiedi all'utente di inserire l'input
    printf("Inserisci l'input: ");
    scanf("%s", input);

    // Apri il file in lettura
    FILE *file = fopen(filename, "r");

    // Verifica che il file sia stato aperto correttamente
    if (file == NULL) {
        printf("Impossibile aprire il file %s\n", filename);
        return 1;
    }

    // Leggi il file riga per riga e confronta con l'input
    while (fgets(buffer, MAX_STRING_LENGTH, file) != NULL) {
        // Rimuovi il carattere di fine riga
        buffer[strcspn(buffer, "\n")] = '\0';

        // Cerca il carattere "#" nella riga
        comment = strchr(buffer, '#');

        // Se il carattere "#" viene trovato, estrai il testo dopo di esso
        if (comment != NULL) {
            *comment = '\0'; // Rimuovi il commento dalla riga
            comment++; // Sposta il puntatore al carattere successivo al "#"
        }

        // Confronta la stringa estratta con l'input
        if (strcmp(buffer, input) == 0) {
            // Se viene trovata una corrispondenza, stampa il testo dopo il carattere "#"
            if (comment != NULL) {
                printf("Corrispondenza trovata: %s\n", comment);
            } else {
                printf("Corrispondenza non trovata\n");
            }
            break;
        }
    }

    // Chiudi il file
    fclose(file);

    return 0;
}


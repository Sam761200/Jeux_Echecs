#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 8

// Énumération pour représenter les types de pièces
typedef enum {
    VIDE, ROI, REINE, TOUR, FOU, CAVALIER, PION
} TypePiece;

// Énumération pour représenter les couleurs
typedef enum {
    AUCUNE, BLANC, NOIR
} Couleur;

// Structure pour représenter une pièce
typedef struct {
    TypePiece type;
    Couleur couleur;
} Piece;

// Initialisation de l'échiquier avec des pièces
void initialiserEchiquier(Piece echiquier[TAILLE][TAILLE]) {
    // Initialiser toutes les cases à vide
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            echiquier[i][j].type = VIDE;
            echiquier[i][j].couleur = AUCUNE;
        }
    }

    // Placer les pièces blanches
    echiquier[0][0] = (Piece){TOUR, BLANC};
    echiquier[0][1] = (Piece){CAVALIER, BLANC};
    echiquier[0][2] = (Piece){FOU, BLANC};
    echiquier[0][3] = (Piece){REINE, BLANC};
    echiquier[0][4] = (Piece){ROI, BLANC};
    echiquier[0][5] = (Piece){FOU, BLANC};
    echiquier[0][6] = (Piece){CAVALIER, BLANC};
    echiquier[0][7] = (Piece){TOUR, BLANC};
    for (int i = 0; i < TAILLE; i++) {
        echiquier[1][i] = (Piece){PION, BLANC};
    }

    // Placer les pièces noires
    echiquier[7][0] = (Piece){TOUR, NOIR};
    echiquier[7][1] = (Piece){CAVALIER, NOIR};
    echiquier[7][2] = (Piece){FOU, NOIR};
    echiquier[7][3] = (Piece){REINE, NOIR};
    echiquier[7][4] = (Piece){ROI, NOIR};
    echiquier[7][5] = (Piece){FOU, NOIR};
    echiquier[7][6] = (Piece){CAVALIER, NOIR};
    echiquier[7][7] = (Piece){TOUR, NOIR};
    for (int i = 0; i < TAILLE; i++) {
        echiquier[6][i] = (Piece){PION, NOIR};
    }
}

// Affichage de l'échiquier
void afficherEchiquier(Piece echiquier[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            char symbole = ' ';
            switch (echiquier[i][j].type) {
                case ROI: symbole = (echiquier[i][j].couleur == BLANC) ? 'R' : 'r'; break;
                case REINE: symbole = (echiquier[i][j].couleur == BLANC) ? 'Q' : 'q'; break;
                case TOUR: symbole = (echiquier[i][j].couleur == BLANC) ? 'T' : 't'; break;
                case FOU: symbole = (echiquier[i][j].couleur == BLANC) ? 'F' : 'f'; break;
                case CAVALIER: symbole = (echiquier[i][j].couleur == BLANC) ? 'C' : 'c'; break;
                case PION: symbole = (echiquier[i][j].couleur == BLANC) ? 'P' : 'p'; break;
                default: symbole = '.'; break;
            }
            printf("%c ", symbole);
        }
        printf("\n");
    }
}

int main() {
    Piece echiquier[TAILLE][TAILLE];
    initialiserEchiquier(echiquier);
    afficherEchiquier(echiquier);
    return 0;
}

//
//  ChessPiece.c
//  ChessGame
//
//  Created by Brian Sanders on 7/24/21.
//

#include "ChessPiece.h"
#include <stdlib.h>

typedef struct OpaqueChessPiece {
  ChessPieceColor color;
  ChessPieceType type;
} ChessPiece;

ChessPieceRef ChessPieceCreate(PieceColors aColor, PieceType aType) {
  ChessPieceRef thePiece = (ChessPieceRef) malloc(sizeof(ChessPiece));
  *thePiece = (ChessPiece){
    .color = aColor,
    .type = aType
  };
  return thePiece;
}

ChessPieceColor ChessPieceGetColor(ChessPieceRef aPiece) {
  if (!aPiece) { return -1; }
  return aPiece->color;
}
ChessPieceType ChessPieceGetType(ChessPieceRef aPiece) {
  if (!aPiece) { return -1; }
  return aPiece->type;
}

char* ChessPieceGetTypeString(ChessPieceRef aPiece) {
  if (!aPiece) { return ""; }
  switch (aPiece->type) {
    case pawn:
      return "pawn";
    case rook:
      return "rook";
    case bishop:
      return "bishop";
    case knight:
      return "knight";
    case queen:
      return "queen";
    case king:
      return "king";
    default:
      return "";
  }
}

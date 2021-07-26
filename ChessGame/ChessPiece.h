//
//  ChessPiece.h
//  ChessGame
//
//  Created by Brian Sanders on 7/24/21.
//

#ifndef ChessPiece_h
#define ChessPiece_h

#include <stdint.h>
#include "Errors.h"

typedef struct OpaqueChessPiece ChessPiece;
typedef struct OpaqueChessPiece *ChessPieceRef;

typedef int8_t ChessPieceColor;
typedef int8_t ChessPieceType;

typedef enum {
  white=0,
  black=1,
} PieceColors;

typedef enum {
  pawn,
  rook,
  knight,
  bishop,
  queen,
  king
} PieceType;

extern ChessPieceRef ChessPieceCreate(PieceColors aColor, PieceType aType);
// Returns Piece color, or -1 if piece is null.
extern ChessPieceColor ChessPieceGetColor(ChessPieceRef aPiece);
// Returns Piece color, or -1 if piece is null.
extern ChessPieceType ChessPieceGetType(ChessPieceRef aPiece);
extern char* ChessPieceGetTypeString(ChessPieceRef aPiece);

extern StatusCode ChessPieceTransformPiece(ChessPieceRef aPiece, ChessPieceType aType);

#endif /* ChessPiece_h */

//
//  ChessPiece.h
//  ChessGame
//
//  Created by Brian Sanders on 7/24/21.
//

#ifndef ChessPiece_h
#define ChessPiece_h

#include <stdint.h>

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

ChessPieceRef ChessPieceCreate(PieceColors aColor, PieceType aType);
char* ChessPieceGetTypeString(ChessPieceRef aPiece);

#endif /* ChessPiece_h */

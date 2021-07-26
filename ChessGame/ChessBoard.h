//
//  ChessBoard.h
//  ChessGame
//
//  Created by Brian Sanders on 7/24/21.
//

#ifndef ChessBoard_h
#define ChessBoard_h

#include <CoreFoundation/CoreFoundation.h>
#include "Errors.h"
#include "ChessPiece.h"

typedef struct OpaqueChessBoard ChessBoard;
typedef struct OpaqueChessBoard *ChessBoardRef;

typedef enum {
  A = 0,
  B, C, D, E, F, G, H
} ROW_COORDINATES;

typedef enum {
  BoardLayoutDefault = 0
} BoardLayouts;

typedef int BoardLayout;

extern StatusCode ChessBoardInitBoard(ChessBoardRef *aBoard, BoardLayout aLayout);
/* Frees all pieces on the board, and the board itself.
 Returns noError if successful. */
extern StatusCode ChessBoardTearDown(ChessBoardRef);
extern ChessPieceRef ChessBoardGetPieceAtIndex(ChessBoardRef aBoard, size_t aRow, size_t aColumn);
#endif /* ChessBoard_h */

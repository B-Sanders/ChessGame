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

/* Functions which take action on the board assume no knowledge about the game being played.
 Do not expect invalid moves to be rejected by the functions, unless there is an index out-of-bounds, you are requesting to make an action on a coordinate in which a piece does not actually live, or similar egregious inputs are given.
 */

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
/* Moves piece in from coordinates to "to coordinates", and does no validation, except for checking that there is a valid piece in the from coordinates on the board.  It is up to the caller to verify that the piece being moved is valid in terms of the games rules. */
extern StatusCode ChessBoardMovePieceAtIndex(ChessBoardRef aBoard,
                                             size_t aFromRow,
                                             size_t aFromColumn,
                                             size_t aToRow,
                                             size_t aToColumn
                                             );
/* Transforms piece at given coordinates to the given type.
 Function assumes a valid type, and valid piece to transform. */
extern StatusCode ChessBoardTransformPieceAtIndex(ChessBoardRef aBoard, ChessPieceType aType, size_t aRow, size_t aColumn);
#endif /* ChessBoard_h */

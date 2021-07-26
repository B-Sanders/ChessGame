//
//  ChessBoard.c
//  ChessGame
//
//  Created by Brian Sanders on 7/24/21.
//

#include "ChessBoard.h"

#define INVALID_INDEX SIZE_MAX
#define DEFAULT_WIDTH 8
#define DEFAULT_HEIGHT 8


typedef struct OpaqueChessBoard {
  size_t width;
  size_t height;
  ChessPieceRef board[DEFAULT_HEIGHT][DEFAULT_WIDTH];
} ChessBoard;

static StatusCode CreateDefaultChessBoard(ChessBoardRef *aBoard) {
  StatusCode theStatus = noError;
  // TODO: this is some error, I am only allocating space for the board array not the struct.
  *aBoard = malloc(sizeof(ChessBoard));
  **aBoard = (ChessBoard){
    .width = DEFAULT_WIDTH,
    .height = DEFAULT_HEIGHT,
  };
  if (!(*aBoard)) {
    theStatus = failedToAllocMemory;
    goto bail;
  }
  
#define WHITE_PAWN_ROW_HEIGHT 1
#define BLACK_PAWN_ROW_HEIGHT 6
  
  // Init pawns
  for (int i = 0; i < DEFAULT_WIDTH; i++) {
    ChessPieceRef theWhitePawn = ChessPieceCreate(white, pawn);
    (*aBoard)->board[WHITE_PAWN_ROW_HEIGHT][i] = theWhitePawn;
    ChessPieceRef theBlackPawn = ChessPieceCreate(black, pawn);
    (*aBoard)->board[BLACK_PAWN_ROW_HEIGHT][i] = theBlackPawn;
  }
  
  // Init rooks
  (*aBoard)->board[0][0] = ChessPieceCreate(white, rook);
  (*aBoard)->board[0][DEFAULT_WIDTH - 1] = ChessPieceCreate(white, rook);
  
  (*aBoard)->board[DEFAULT_HEIGHT - 1][0] = ChessPieceCreate(black, rook);
  (*aBoard)->board[DEFAULT_HEIGHT - 1][DEFAULT_WIDTH - 1] = ChessPieceCreate(black, rook);
  
  // Init knights
  (*aBoard)->board[0][1] = ChessPieceCreate(white, knight);
  (*aBoard)->board[0][DEFAULT_WIDTH - 2] = ChessPieceCreate(white, knight);
  
  (*aBoard)->board[DEFAULT_HEIGHT - 1][1] = ChessPieceCreate(black, knight);
  (*aBoard)->board[DEFAULT_HEIGHT - 1][DEFAULT_WIDTH - 2] = ChessPieceCreate(black, knight);
  
  // Init bishops
  (*aBoard)->board[0][2] = ChessPieceCreate(white, bishop);
  (*aBoard)->board[0][DEFAULT_WIDTH - 3] = ChessPieceCreate(white, bishop);
  
  (*aBoard)->board[DEFAULT_HEIGHT - 1][2] = ChessPieceCreate(black, bishop);
  (*aBoard)->board[DEFAULT_HEIGHT - 1][DEFAULT_WIDTH - 3] = ChessPieceCreate(black, bishop);
  
  // Init queens
  (*aBoard)->board[0][3] = ChessPieceCreate(white, queen);
  (*aBoard)->board[DEFAULT_HEIGHT - 1][3] = ChessPieceCreate(black, queen);
  
  // Init kings
  (*aBoard)->board[0][4] = ChessPieceCreate(white, king);
  (*aBoard)->board[DEFAULT_HEIGHT - 1][4] = ChessPieceCreate(black, king);
  
  return theStatus;
bail:
  // Perform memory cleanup in error state
  for (int i = 0; i < DEFAULT_HEIGHT; i++) {
    for (int j = 0; i < DEFAULT_WIDTH; j++) {
      free((*aBoard)->board[i][j]);
    }
  }
  free(*aBoard);
  return theStatus;
}



StatusCode ChessBoardInitBoard(ChessBoardRef *aBoard,
                               BoardLayout aLayout
                               ) {
  StatusCode theStatus = noError;
  if (*aBoard) {
    theStatus = expectedNullPtr;
    goto bail;
  }
  if (aLayout == BoardLayoutDefault) {
    theStatus = CreateDefaultChessBoard(aBoard);
  }
  
bail:
  return theStatus;
}

StatusCode ChessBoardTearDown(ChessBoardRef aBoard) {
  if (!aBoard) { return badPointer; }
  for (int i = 0; i < aBoard->height; i++) {
    for (int j = 0; j < aBoard->width; j++) {
      free(aBoard->board[i][j]);
    }
  }
  free(aBoard);
  return noError;
}

ChessPieceRef ChessBoardGetPieceAtIndex(ChessBoardRef aBoard, size_t aRow, size_t aColumn) {
  if (!aBoard || aRow >= aBoard->height || aColumn >= aBoard->width) {
    return NULL;
  }
  return aBoard->board[aRow][aColumn];
}

StatusCode ChessBoardMovePieceAtIndex(ChessBoardRef aBoard,
                                      size_t aFromRow,
                                      size_t aFromColumn,
                                      size_t aToRow,
                                      size_t aToColumn
                                      ) {
  StatusCode theStatus = noError;
  if (!aBoard) {
    theStatus = badPointer;
    goto bail;
  }
  if (aFromRow >= aBoard->height ||
      aFromColumn >= aBoard->width ||
      aToRow >= aBoard->height ||
      aToColumn >= aBoard->width) {
    theStatus = indexOutOfBounds;
    goto bail;
  }
  ChessPieceRef theMovingPiece = ChessBoardGetPieceAtIndex(aBoard, aFromRow, aFromColumn);
  if (!theMovingPiece) {
    theStatus = invalidPieceCoordinate;
    goto bail;
  }
  ChessPieceRef theToSquarePiece = ChessBoardGetPieceAtIndex(aBoard, aToRow, aToColumn);
  if (theToSquarePiece) { free(theToSquarePiece); }
  aBoard->board[aToRow][aToColumn] = theMovingPiece;
  aBoard->board[aFromRow][aFromColumn] = NULL;
  
bail:
  return theStatus;
}

extern StatusCode ChessBoardTransformPieceAtIndex(ChessBoardRef aBoard, ChessPieceType aType, size_t aRow, size_t aColumn) {
  StatusCode theResult = noError;
  if (!aBoard) {
    theResult = badPointer;
    goto bail;
  }
  if (aRow >= aBoard->height || aColumn >= aBoard->width) {
    theResult = indexOutOfBounds;
    goto bail;
  }
  ChessPieceRef thePiece = ChessBoardGetPieceAtIndex(aBoard, aRow, aColumn);
  if (!thePiece) {
    theResult = invalidPieceCoordinate;
    goto bail;
  }
  theResult = ChessPieceTransformPiece(thePiece, aType);
  
bail:
  return theResult;
}


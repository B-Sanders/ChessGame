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
  bool whiteCanCastle;
  bool blackCanCastle;
  bool enPassantPossible;
  ChessPieceRef board[DEFAULT_HEIGHT][DEFAULT_WIDTH];
} ChessBoard;

static StatusCode CreateDefaultChessBoard(ChessBoardRef *aBoard) {
  StatusCode theStatus = noError;
  // TODO: this is some error, I am only allocating space for the board array not the struct.
  *aBoard = malloc(sizeof(ChessBoard));
  **aBoard = (ChessBoard){
    .width = DEFAULT_WIDTH,
    .height = DEFAULT_HEIGHT,
    .whiteCanCastle = true,
    .blackCanCastle = true
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

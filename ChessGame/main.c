//
//  main.c
//  ChessGame
//
//  Created by Brian Sanders on 7/24/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>
#include "Errors.h"

#include "ChessBoard.h"

int main(int argc, const char * argv[]) {
  
  ChessBoardRef theBoard = NULL;
  StatusCode theCode = ChessBoardInitBoard(&theBoard, BoardLayoutDefault);
  ErrorHandleCode(theCode);
  
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      ChessPieceRef thePiece = ChessBoardGetPieceAtIndex(theBoard, i, j);
      if (!thePiece) {
        printf("[%d][%d] is empty\n", i, j);
      } else {
        printf("[%d][%d] is a %s\n", i, j, ChessPieceGetTypeString(thePiece));
      }
    }
  }
  return 0;
}

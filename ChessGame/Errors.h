//
//  Errors.h
//  ChessGame
//
//  Created by Brian Sanders on 7/24/21.
//

#ifndef Errors_h
#define Errors_h

#include <stdint.h>

typedef uint32_t StatusCode;

typedef enum {
  noError = 0,
  unknownError = 1,
  badPointer = 2,
  failedToAllocMemory = 3,
  indexOutOfBounds = 4,
  // 100 - 199 Board Errors
  invalidBoardSize = 100,
  expectedNullPtr = 101
} statusCodes;

void ErrorHandleCode(StatusCode aStatusCode);

#endif /* Errors_h */

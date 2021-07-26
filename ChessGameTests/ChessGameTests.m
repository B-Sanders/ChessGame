//
//  ChessGameTests.m
//  ChessGameTests
//
//  Created by Brian Sanders on 7/24/21.
//

#import <XCTest/XCTest.h>
#import "../ChessGame/ChessGame.h"

@interface ChessGameTests : XCTestCase

@end

@implementation ChessGameTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testPieceCreate {
  ChessPieceRef theWhitePawn = ChessPieceCreate(white, pawn);
  XCTAssertNotEqual(theWhitePawn, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(theWhitePawn), white, @"Expected white pawn");
  XCTAssertEqual(ChessPieceGetType(theWhitePawn), pawn, @"Expected white pawn");
  free(theWhitePawn);
  
  ChessPieceRef theBlackPawn = ChessPieceCreate(black, pawn);
  XCTAssertNotEqual(theBlackPawn, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(theBlackPawn), black, @"Expected black pawn");
  XCTAssertEqual(ChessPieceGetType(theBlackPawn), pawn, @"Expected black pawn");
  free(theBlackPawn);
  
  ChessPieceRef theWhiteKing = ChessPieceCreate(white, king);
  XCTAssertNotEqual(theWhiteKing, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(theWhiteKing), white, @"Expected white king");
  XCTAssertEqual(ChessPieceGetType(theWhiteKing), king, @"Expected white king");
  free(theWhiteKing);
  
  ChessPieceRef theBlackQueen = ChessPieceCreate(black, queen);
  XCTAssertNotEqual(theBlackQueen, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(theBlackQueen), black, @"Expected black queen");
  XCTAssertEqual(ChessPieceGetType(theBlackQueen), queen, @"Expected black queen");
  free(theBlackQueen);
}

- (void)testBoardCreateAndPiecesAtIndex {
  ChessBoardRef theBoard = NULL;
  StatusCode theResult = ChessBoardInitBoard(&theBoard, BoardLayoutDefault);
  XCTAssertNotEqual(theBoard, NULL, @"Failed to create board");
  XCTAssertEqual(theResult, noError, @"Wrong status result from board");
  
  ChessPieceRef theWhitePawn = ChessBoardGetPieceAtIndex(theBoard, 1, A);
  XCTAssertNotEqual(theWhitePawn, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(theWhitePawn), white, @"Expected white pawn");
  XCTAssertEqual(ChessPieceGetType(theWhitePawn), pawn, @"Expected white pawn");
  
  ChessPieceRef theBlackPawn = ChessBoardGetPieceAtIndex(theBoard, 6, A);
  XCTAssertNotEqual(theBlackPawn, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(theBlackPawn), black, @"Expected black pawn");
  XCTAssertEqual(ChessPieceGetType(theBlackPawn), pawn, @"Expected black pawn");
  
  ChessPieceRef theWhiteKing = ChessBoardGetPieceAtIndex(theBoard, 0, E);
  XCTAssertNotEqual(theWhiteKing, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(theWhiteKing), white, @"Expected white king");
  XCTAssertEqual(ChessPieceGetType(theWhiteKing), king, @"Expected white king");
  
  ChessPieceRef theBlackQueen = ChessBoardGetPieceAtIndex(theBoard, 7, D);
  XCTAssertNotEqual(theBlackQueen, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(theBlackQueen), black, @"Expected black queen");
  XCTAssertEqual(ChessPieceGetType(theBlackQueen), queen, @"Expected black queen");
  
  XCTAssertEqual(ChessBoardTearDown(theBoard), noError, @"Board tear down failed");
}

- (void)testPieceMovementOnBoard {
  // TODO: Maybe this can be moved to setup.
  ChessBoardRef theBoard = NULL;
  StatusCode theResult = ChessBoardInitBoard(&theBoard, BoardLayoutDefault);
  XCTAssertEqual(theResult, noError, @"Board init fail.");
  
  theResult = ChessBoardMovePieceAtIndex(theBoard, 1, A, 3, A);
  XCTAssertEqual(theResult, noError, @"Piece move fail.");
  ChessPieceRef theFromSquare = ChessBoardGetPieceAtIndex(theBoard, 1, A);
  XCTAssertEqual(theFromSquare, NULL, @"Piece not properly removed from original square.");
  ChessPieceRef theToSquare = ChessBoardGetPieceAtIndex(theBoard, 3, A);
  XCTAssertNotEqual(theToSquare, NULL, @"Piece not properly moved to desired square.");
  XCTAssertEqual(ChessPieceGetColor(theToSquare), white, @"Expected white pawn");
  XCTAssertEqual(ChessPieceGetType(theToSquare), pawn, @"Expected white pawn");
  
  // TODO: Maybe this can be moved to tear down.
  XCTAssertEqual(ChessBoardTearDown(theBoard), noError, @"Board tear down failed");
}

- (void)testPieceTransform {
  ChessBoardRef theBoard = NULL;
  StatusCode theResult = ChessBoardInitBoard(&theBoard, BoardLayoutDefault);
  XCTAssertEqual(theResult, noError, @"Board init fail.");
  
  theResult = ChessBoardTransformPieceAtIndex(theBoard, queen, 1, A);
  XCTAssertEqual(theResult, noError, @"Piece move fail.");
  
  ChessPieceRef thePiece = ChessBoardGetPieceAtIndex(theBoard, 1, A);
  XCTAssertNotEqual(thePiece, NULL, @"Should return valid piece");
  XCTAssertEqual(ChessPieceGetColor(thePiece), white, @"Expected white queen");
  XCTAssertEqual(ChessPieceGetType(thePiece), queen, @"Expected white queen");
  
  XCTAssertEqual(ChessBoardTearDown(theBoard), noError, @"Board tear down failed");
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end

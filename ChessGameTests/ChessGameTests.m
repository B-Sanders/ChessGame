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
  StatusCode theCode = ChessBoardInitBoard(&theBoard, BoardLayoutDefault);
  XCTAssertNotEqual(theBoard, NULL, @"Failed to create board");
  XCTAssertEqual(theCode, 0, @"Wrong status result from board");
  
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
  
  ChessBoardTearDown(theBoard);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end

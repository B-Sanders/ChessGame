//
//  Errors.c
//  ChessGame
//
//  Created by Brian Sanders on 7/24/21.
//

#include "Errors.h"
#include <stdlib.h>
#include <stdio.h>

void ErrorHandleCode(StatusCode aStatusCode) {
  if (aStatusCode) {
    printf("The program has terminated due to error: %d\n", aStatusCode);
    exit(EXIT_FAILURE);
  }
}

//#include <CoreFoundation/CoreFoundation.h>
//
//#define NUM_STATUS_CODES 4

//static CFNumberRef theErrorCodes[] = {
//  CFNumberCreate(kCFAllocatorDefault, CFNumberTy,) 0,
//  1,
//  2,
//  100
//};

//static CFStringRef theErrorStatuses[] = {
//  CFSTR("No error"), // 0
//  CFSTR("Unknown error"), // 1
//  CFSTR("Bad Pointer"), // 2
//
//  CFSTR("Invalid board size") // 100
//};

//void ErrorHandleCode(StatusCode aStatusCode) {
//  static CFDictionaryRef theStatusCodeMap = NULL;
//  if (!theStatusCodeMap) {
//    theStatusCodeMap = CFDictionaryCreate(kCFAllocatorDefault,
//                       (const void**) theErrorCodes,
//                       (const void**) theErrorStatuses,
//                       NUM_STATUS_CODES,
//                       &kCFTypeDictionaryKeyCallBacks,
//                       &kCFTypeDictionaryValueCallBacks);
//  }
//
//  if (aStatusCode) {
//
//    for (size_t i = 0; i < NUM_STATUS_CODES; i++) {
//      CFRelease(theErrorStatuses[i]);
//    }
//    CFStringRef theStatusCodeStr = CFDictionaryGetValue(theStatusCodeMap, (void*) aStatusCode);
//
//    char* thePrintableStatus;
//    if (!theStatusCodeStr) { thePrintableStatus = "Unknown error"; }
//    else {
//      thePrintableStatus = CFStringGetCStringPtr(theStatusCodeStr, CFStringGetSystemEncoding());
//    }
//    printf("The program has terminated due to: %s\n", thePrintableStatus);
//    CFRelease(theStatusCodeMap);
//    exit(EXIT_FAILURE);
//  }
//}

/*
 *  sqMacExtendedClipboard.h
 *  SqueakClipboardExtendedxcodeproj
 *
 *  Created by John Sterling Mcintosh on 4/21/06.
 *  Copyright 2006-2010 Corporate Smalltalk Consulting ltd. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *  OTHER DEALINGS IN THE SOFTWARE.
 *
 */
/* The virtual machine proxy definition */
#include "sqVirtualMachine.h"
#ifdef BUILD_FOR_OSX
#import <Cocoa/Cocoa.h>
typedef NSPasteboard * CLIPBOARDTYPE;
#else
typedef UIPasteboard * CLIPBOARDTYPE;
#endif

void sqPasteboardClear(CLIPBOARDTYPE inPasteboard);
sqInt sqPasteboardGetItemCount(CLIPBOARDTYPE inPasteboard);
sqInt sqPasteboardCopyItemFlavorsitemNumber(CLIPBOARDTYPE inPasteboard, sqInt formatNumber);
void *sqCreateClipboard(void);
void sqPasteboardPutItemFlavordatalengthformatTypeformatLength(CLIPBOARDTYPE inPasteboard, char* inData, sqInt dataLength, char* format, sqInt formatLength);
sqInt sqPasteboardCopyItemFlavorDataformatformatLength(CLIPBOARDTYPE inPasteboard, char* format, sqInt formatLength);
sqInt sqPasteboardCopyItemFlavorDataformat(CLIPBOARDTYPE inPasteboard, sqInt format);
sqInt sqPasteboardhasDataInFormatformatLength(CLIPBOARDTYPE inPasteboard, char* format, sqInt formatLength);
sqInt sqPasteboardhasDataInFormat(CLIPBOARDTYPE inPasteboard, sqInt format);

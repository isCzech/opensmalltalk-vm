//
//  sqSqueakOSXOpenGLView.h
//  SqueakPureObjc
//
//  Created by John M McIntosh on 09-11-14.
/*
 Some of this code was funded via a grant from the European Smalltalk User Group (ESUG)
 Copyright 2009 Corporate Smalltalk Consulting Ltd. All rights reserved.
 MIT License
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 
 The end-user documentation included with the redistribution, if any, must include the following acknowledgment: 
 "This product includes software developed by Corporate Smalltalk Consulting Ltd (http://www.smalltalkconsulting.com) 
 and its contributors", in the same place and form as other third-party acknowledgments. 
 Alternately, this acknowledgment may appear in the software itself, in the same form and location as other 
 such third-party acknowledgments.
 */
//

#ifdef USE_OPENGL
#import <Cocoa/Cocoa.h>
#include <ApplicationServices/ApplicationServices.h>
#import "keyBoardStrokeDetails.h"
#import "sqSqueakOSXView.h"
#import	"SqViewClut.h"

@class sqSqueakOSXScreenAndWindow;
#import "sq.h"
#import <OpenGL/gl.h>

@interface sqSqueakOSXOpenGLView : NSOpenGLView <sqSqueakOSXView, sqViewClut, NSTextInputClient> {
	sqSqueakOSXScreenAndWindow *__weak windowLogic;
	NSRange inputMark;
	NSRange inputSelection;
	keyBoardStrokeDetails* lastSeenKeyBoardStrokeDetails;
	keyBoardStrokeDetails* lastSeenKeyBoardModifierDetails;
	BOOL	dragInProgress;
	int		dragCount;
	BOOL	firstDrawCompleted;
	BOOL	syncNeeded;
	CGDisplayFadeReservationToken    fadeToken;
	CGColorSpaceRef colorspace;
	unsigned int*      colorMap32;
    BOOL clippyIsEmpty;
	CGRect clippy;
    NSRect lastFrameSize;
    BOOL fullScreenInProgress;
    void* fullScreendispBitsIndex;
	void* currentDisplayStorage;
	
	BOOL openglInitialized;
	BOOL hasVertexArrayObject;
	GLuint textureProgram;
	GLuint rectangleTextureProgram;
	GLint screenSizeUniformLocation;
	GLint layerScaleAndTranslationUniformLocation;
	
	GLuint screenQuadVertexBuffer;
	GLuint screenQuadVertexArray;
	
	GLuint displayTexture;
	int displayTextureWidth;
	int displayTextureHeight;
}

- (void) setupOpenGL;
- (void) preDrawThelayers;
- (NSRect) sqScreenSize;
- (NSPoint) sqMousePosition: (NSEvent*)theEvent;
- (NSPoint) sqDragPosition: (NSPoint)draggingLocation;
@end
#endif //USE_OPENGL

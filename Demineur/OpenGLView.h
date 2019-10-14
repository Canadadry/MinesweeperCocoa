//
//  OpenGLView.h
//  Demineur
//
//  Created by mooglwy on 30/08/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OpenGLView : NSOpenGLView
{
	NSTimer*       timer;
	NSSize         sizeView;
	CFAbsoluteTime time;
}

// window stuff
//- (id)   init;
- (id)   initWithFrame: (NSRect) frameRect;
- (void) awakeFromNib;
- (void) prepareOpenGL;
- (void) dealloc;
- (BOOL) acceptsFirstResponder;
- (BOOL) becomeFirstResponder;
- (BOOL) resignFirstResponder;

// opengl stuff
- (void) animationTimer:(NSTimer *)timer;
- (void) drawRect:(NSRect)dirtyRect;

//subclasse
- (NSOpenGLPixelFormat*) basicPixelFormat;
- (void) resizeToWidth:(int) width andHeight:(int)height;
- (void) initGL;
- (void) paintGL;
- (void) updateGL:(int)elapsedTimeInUs;

@end

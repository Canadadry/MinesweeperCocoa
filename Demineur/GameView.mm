//
//  GameView.m
//  Demineur
//
//  Created by mooglwy on 31/08/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "GameView.h"
#import <OpenGL/gl.h>
#import <OpenGL/glu.h>

#include "game.h"

@implementation GameView

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) 
	{
		[[NSFileManager defaultManager] changeCurrentDirectoryPath:[[NSBundle mainBundle] resourcePath]];
    }
    
    return self;
}

-(void) dealloc
{
	[super dealloc];
}

- (IBAction)restartGame:(id)sender
{
	m_game->startGame(9,9,10);
	[self setSize:[GameView makeSizeFromWidth:m_game->width() andHeight:m_game->height()]];	
}

- (void) initGL
{
	m_game = new Game();
	[self restartGame:nil];
}

- (void) resizeToWidth:(int)width andHeight:(int)height
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);    
	glLoadIdentity();           
	gluOrtho2D(0,width,0,height);
	
}

- (void)paintGL
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_game->display();
}


+(NSSize) makeSizeFromWidth:(float)width andHeight:(float) height
{
	NSSize size;
	size.width  = width;
	size.height = height;
	return size;
}

-(void) setSize:(NSSize) size
{
	NSRect rect = [[self window] frame];
	rect.size = size;
	rect = [[self window] frameRectForContentRect: rect];
	[[self window] setFrame:rect display:YES animate:YES];
	[[self window] setMinSize:rect.size];
	[[self window] setMaxSize:rect.size];
	
}

- (NSPoint) flip_y:(NSPoint) location
{
    // Get openGL context size
    NSRect rectView = [self bounds];
    // Cocoa gives opposite of OpenGL y direction, flip y direction
    location.y = rectView.size.height - location.y;
    return location;
}



- (void) mouseDown:(NSEvent *)theEvent{}
- (void) rightMouseDown:(NSEvent *)theEvent{}
- (void) otherMouseDown:(NSEvent *)theEvent{}
- (void) mouseUp:(NSEvent *)theEvent
{
	NSPoint loc = [self flip_y:[self convertPoint:[theEvent locationInWindow] fromView:nil]];
	m_game->mouseLeftUp(loc.x, loc.y);
}

- (void) rightMouseUp:(NSEvent *)theEvent
{
	NSPoint loc = [self flip_y:[self convertPoint:[theEvent locationInWindow] fromView:nil]];
	m_game->mouseRightUp(loc.x, loc.y);
}

- (void) otherMouseUp:(NSEvent *)theEvent{}
- (void) mouseMoved:(NSEvent *)theEvent{}
- (void) mouseDragged:(NSEvent *)theEvent{}
- (void) rightMouseDragged:(NSEvent *)theEvent{}
- (void) otherMouseDragged:(NSEvent *)theEvent{}


@end

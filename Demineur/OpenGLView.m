//
//  OpenGLView.m
//  Demineur
//
//  Created by mooglwy on 30/08/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "OpenGLView.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

static CFAbsoluteTime gStartTime = 0.0f;

// set app start time
static void setStartTime (void)
{	
	gStartTime = CFAbsoluteTimeGetCurrent ();
}

// return float elpased time in seconds since app start
static CFAbsoluteTime getElapsedTime (void)
{	
	return CFAbsoluteTimeGetCurrent () - gStartTime;
}

@implementation OpenGLView

-(id) initWithFrame: (NSRect) frameRect
{
	NSOpenGLPixelFormat * pf = [self basicPixelFormat];
	
	self = [super initWithFrame: frameRect pixelFormat: pf];
	
    return self;
}

// pixel format definition
- (NSOpenGLPixelFormat*) basicPixelFormat
{
    NSOpenGLPixelFormatAttribute attributes [] = {
        NSOpenGLPFAWindow,
        NSOpenGLPFADoubleBuffer,	// double buffered
        NSOpenGLPFADepthSize, (NSOpenGLPixelFormatAttribute)16, // 16 bit depth buffer
        (NSOpenGLPixelFormatAttribute)nil
    };
	
	NSOpenGLPixelFormat* pxlFmt =  [[[NSOpenGLPixelFormat alloc] initWithAttributes:attributes] autorelease];
	
	if(pxlFmt == nil) NSLog(@"enable to find suitable pixl format");
	
	return pxlFmt;
}

- (void) awakeFromNib
{
	setStartTime (); // get app start time
	time = CFAbsoluteTimeGetCurrent ();  // set animation time start time
	// start animation timer
	timer = [NSTimer timerWithTimeInterval:(1.0f/60.0f) target:self selector:@selector(animationTimer:) userInfo:nil repeats:YES];
	[[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
	[[NSRunLoop currentRunLoop] addTimer:timer forMode:NSEventTrackingRunLoopMode]; // ensure timer fires during resize
	
}

- (BOOL)acceptsFirstResponder
{
	return YES;
}

- (BOOL)becomeFirstResponder
{
	return  YES;
}

- (BOOL)resignFirstResponder
{
	return YES;
}

- (void)prepareOpenGL
{
    const GLint swapInt = 1;
    [[self openGLContext] setValues:&swapInt forParameter:NSOpenGLCPSwapInterval]; 

	[self initGL];
}

- (void)dealloc
{
	[super dealloc];
}

// per-window timer function, basic time based animation preformed here
- (void)animationTimer:(NSTimer *)timer
{
	[self drawRect:[self bounds]];
}


-(void)drawRect:(NSRect)dirtyRect
{
	NSSize currentSize = [self bounds].size;
	
	if ((currentSize.height != sizeView.height) || (currentSize.width != sizeView.width)) 
	{
		sizeView = currentSize;
		[self resizeToWidth:sizeView.width andHeight:sizeView.height];
	}
	
	[self updateGL:0];
	
	[self paintGL];
	
	glFlush();
	[[self openGLContext] flushBuffer];
}


- (void) resizeToWidth:(int) width andHeight:(int)height
{
	glViewport(0, 0, width, height);
	
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, (float)width/ (float)height, 1.f, 500.f);
	
}


- (void) initGL
{
	// init GL stuff here
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	
}

- (void) paintGL
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.f, 0.f, -200.f);
	glRotatef(getElapsedTime() * 50, 1.f, 0.f, 0.f);
	glRotatef(getElapsedTime() * 30, 0.f, 1.f, 0.f);
	glRotatef(getElapsedTime() * 90, 0.f, 0.f, 1.f);
	
	glBegin(GL_QUADS);
	
    glVertex3f(-50.f, -50.f, -50.f);
    glVertex3f(-50.f,  50.f, -50.f);
    glVertex3f( 50.f,  50.f, -50.f);
    glVertex3f( 50.f, -50.f, -50.f);
	
    glVertex3f(-50.f, -50.f, 50.f);
    glVertex3f(-50.f,  50.f, 50.f);
    glVertex3f( 50.f,  50.f, 50.f);
    glVertex3f( 50.f, -50.f, 50.f);
	
    glVertex3f(-50.f, -50.f, -50.f);
    glVertex3f(-50.f,  50.f, -50.f);
    glVertex3f(-50.f,  50.f,  50.f);
    glVertex3f(-50.f, -50.f,  50.f);
	
    glVertex3f(50.f, -50.f, -50.f);
    glVertex3f(50.f,  50.f, -50.f);
    glVertex3f(50.f,  50.f,  50.f);
    glVertex3f(50.f, -50.f,  50.f);
	
    glVertex3f(-50.f, -50.f,  50.f);
    glVertex3f(-50.f, -50.f, -50.f);
    glVertex3f( 50.f, -50.f, -50.f);
    glVertex3f( 50.f, -50.f,  50.f);
	
    glVertex3f(-50.f, 50.f,  50.f);
    glVertex3f(-50.f, 50.f, -50.f);
    glVertex3f( 50.f, 50.f, -50.f);
    glVertex3f( 50.f, 50.f,  50.f);
	
	glEnd();

}

- (void) updateGL:(int)elapsedTimeInUs
{
	
}


@end

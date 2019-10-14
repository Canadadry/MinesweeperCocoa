//
//  GameView.h
//  Demineur
//
//  Created by mooglwy on 31/08/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "OpenGLView.h"
#include <string>

class Game;

@interface GameView : OpenGLView
{
	Game* m_game;
	std::string m_ressourcePath;
}

- (IBAction)restartGame:(id)sender;

- (id)   initWithFrame:(NSRect)frame;
- (void) dealloc;
- (void) initGL;
- (void) paintGL;

- (void) mouseDown:(NSEvent *)theEvent;
- (void) rightMouseDown:(NSEvent *)theEvent;
- (void) otherMouseDown:(NSEvent *)theEvent;
- (void) mouseUp:(NSEvent *)theEvent;
- (void) rightMouseUp:(NSEvent *)theEvent;
- (void) otherMouseUp:(NSEvent *)theEvent;

- (void) mouseMoved:(NSEvent *)theEvent;
- (void) mouseDragged:(NSEvent *)theEvent;
- (void) rightMouseDragged:(NSEvent *)theEvent;
- (void) otherMouseDragged:(NSEvent *)theEvent;


@end

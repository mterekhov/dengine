//
//  ViewController.swift
//  doom
//
//  Created by cipher on 11.12.2023.
//

import Cocoa
import MetalKit

class ViewController: NSViewController, MTKViewDelegate {
    
    private var lastMousePoint = NSZeroPoint
    private let ganeshaBridge = CPPBridge()
    private var ganeshaReady = false
    private var previousMousePoint = NSZeroPoint;

    override var acceptsFirstResponder: Bool {
        get {
            return true
        }
    }
    
    override func viewDidAppear() {
        super.viewDidAppear()

        CGDisplayMoveCursorToPoint(CGMainDisplayID(), screenCenter() ?? NSZeroPoint);
        let trackArea = NSTrackingArea(rect: view.frame, options: [.mouseMoved, .activeInActiveApp], owner: self);
        view.addTrackingArea(trackArea);
//        CGDisplayHideCursor(CGMainDisplayID());
        
        ganeshaBridge.launchEngine(with: view.layer)
        ganeshaReady = true
    }
    
    override func keyDown(with event: NSEvent) {
//        event.isARepeat
        ganeshaBridge.processKeyboardEvent(withKeyCode: event.keyCode);
    }
        
    override func mouseMoved(with event: NSEvent) {
        var mousePoint = event.locationInWindow
        guard let screenCenterPoint = screenCenter() else {
            return
        }
        mousePoint.y += 1;
        
        if lastMousePoint == NSZeroPoint {
            lastMousePoint = mousePoint
        }
        
        if (mousePoint.x > ceil(9.0 * view.bounds.width / 10.0)) ||
            (mousePoint.x < ceil(view.bounds.width / 10.0)) {
            lastMousePoint = screenCenterPoint
            CGDisplayMoveCursorToPoint(CGMainDisplayID(), screenCenterPoint);
            return
        }
        if (mousePoint.y > ceil(9.0 * view.bounds.height / 10.0)) ||
            (mousePoint.y < ceil(view.bounds.height / 10.0)) {
            lastMousePoint = screenCenterPoint
            CGDisplayMoveCursorToPoint(CGMainDisplayID(), screenCenterPoint);
            return
        }

        let diff_x = lastMousePoint.x - mousePoint.x
        let diff_y = lastMousePoint.y - mousePoint.y
        ganeshaBridge.processMouseMove(withDiffX: diff_x, diff_y: diff_y);
        lastMousePoint = mousePoint
    }
    
    func screenCenter() -> NSPoint? {
        return view.window?.convertPoint(toScreen: NSMakePoint(view.frame.width / 2.0, view.frame.height / 2.0));
    }

    //  MARK: - MTKViewDelegate -

    func draw(in view: MTKView) {
        if !ganeshaReady {
            return
        }
        
        ganeshaBridge.drawFrame()
    }

    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) {
        if !ganeshaReady {
            return
        }

        ganeshaBridge.drawableSizeWillChange(size)
    }

}


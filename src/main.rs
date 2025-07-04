use glfw::{Action, Context, Key};
use std::ffi::CString;
use std::sync::mpsc::Receiver; // To receive GLFW in a Seperate thread


// Number of Segments to Approximate Triangle for a circle 
const STEPS: i32 = 100;

// Full Circle divided by the STEPS to get the angular incriment 
const ANGLE_STEP: f32 = std::f32::consts::TAU / STEPS as f32

fn draw_circle(red: f32, green: f32, blue: f32) {

    // Starting point on the unit circle (0,1)

    let mut old_x = 0.0f32;
    let mut old_y = 1.0f32;
    let radius = 1.0f32;

    // Loop from 0 to STEPS to close the circle
    for i in 0..= STEPS {

        let new_x = radius * (ANGLE_STEP * i as f32).sin();
        let new_y = radius * (ANGLE_STEP * i as f32).cos();

        
    }
}

fn main () {
    println!("New project with Rust");
}
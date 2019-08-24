# Led-Programmer-Serial-Print

This most recent code works. The file is called "LightCoder.001" and the breakthrough is documented there.

More Work on the LED programmer. Mainly, a simple serial print to keep safe

Run this big ass thing to see the first code I wrote, run. 

Saved it because of the first half of text. I'll be making more notes, but at some point
I'll need to make ind. readme's. 
/*Hi.
 * 
 * 
 * Fuck you, get out of my code.
 * 
 * If you've found this, then you should know how to do this shit
 * without me teaching you.
 * 
 * This is for Alexander Hudspeth so that he can work on this
 * project and maybe make progress.
 * 
 * save often, keep good
 * notes. These are those notes.
 * 
 * 1. My goal is to blink an LED (then a relay, connected to 
 * an LED pool light), and blink that LED from a app or website.
 * 
 * I need to reproduce the following sequence of "on" and "off"
 * triggers: This pattern is from the Jandy WaterColor RGBW
 * swimming pool light. 
 * 
 * Below is transcribed directly from:
 * 
 * ----Jandy Watercolors Installation and Operation Manual 
 * 
 * Section 6. Jandy Pro Series
 *            WaterColors RGBW
 *            LED Light Operating
 *            Instructions
 *            
 * 6.1. To Operate the Light and Change 
 *      Colors
 * 
 * turn the light ON. The FIRST time the light is turned on,
 * the color sequence begins with the Alpine White. To
 * change the color, turn the light OFF and the ON within 
 * three (3) seconds.  Continue turning OFF and ON until
 * the desired light color mode is reached. See Table 1 for 
 * the color mode sequence.
 * 
 * Table 1. Jandy Pro Series WaterColors Lights
 *          Sequence 
 *   ______________________________________
 *  |Sequence Order|  Color Modes          |
 *  |______________|_______________________|
 *  |        1     |Alpine White           |
 *  |        2     |Sky Blue               |
 *  |        3     |Cobalt Blue            |
 *  |        4     |Caribbean Blue         |
 *  |        5     |Spring Green           |
 *  |        6     |Emerald Green          |
 *  |        7     |Emerald Rose           |
 *  |        8     |Magenta                |
 *  |        9     |Violet                 |
 *  |       10     |Slow Color Splash      |
 *  |       11     |Fast Color Splash      |
 *  |       12     |America the Beautiful  |
 *  |       13     |Fat Tuesday            |
 *  |       14     |Disco Tech             |
 *  |______________|_______________________|
 * 
 * When the light is turned OFF for more than seven (7)
 * seconds, it will remain in the color set that is currently
 * active. When the light is turned back ON, the light will
 * be on the same color set.
 * 
 * 6.2 To Reset to the Beginning of the Color
 *     Sequence
 * Turn the light OFF, wait four (4) to five (5) seconds, then    
 * turn ON, the light will return to the  beginning of the color 
 * cycle (Alpine White).
 * |    
 * |
 * |
 * |
 * |
 * |
 * That's a LOT of data!  
 * 
 * The sketch below will turn an LED ON and OFF if I enter "1" or "2" 
 * in the serial monitor. So, it SORT of works, if I want frantically
 * enter ones and twos in a serial monitor to change my pool lights.
 * So, no, it doesn't work, but it does SOMETHING, which is a start, 
 * I guess.
 * 
 * 
 * 
 * 
 */
 void setup() 
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Input 1 to Turn LED on and 2 to off");
}

void loop()
{
  if (Serial.available())
  {
    int state = Serial.parseInt();
    if (state == 1)
    {
     digitalWrite(13, HIGH);
     Serial.println("Command completed LED turned ON");
    }
    if (state == 2)
    {
     digitalWrite(13, LOW);
     Serial.println("Command completed LED turned OFF");
    }  
  }
}

/*
 * 
 */


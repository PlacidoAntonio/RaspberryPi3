import serial

from evdev import InputDevice, categorize, ecodes
dev = InputDevice('/dev/input/event4')

arduino = serial.Serial('/dev/ttyUSB0',9600)

print("Starting...")
print("Control Menu-----------------------------------------------------")
print("1. R2 to go forward")
print("2. L2 to go back")
print("3. SQUARED to turn left")
print("4. CIRCLE to turn rigth")
print("5. START to exit")
print("-----------------------------------------------------------------")

print(dev)

for event in dev.read_loop():
    
    if event.type == ecodes.EV_KEY:
        boton = categorize(event)
        
        if boton.scancode == 295:
            if boton.keystate == 1:
                print("R2 Clicked...")
                arduino.write("Adelante,")
            else:
                print("R2 Dropped...")
                arduino.write("Parar,")
                
        if boton.scancode == 294:
            if boton.keystate == 1:
                print("L2 Clicked...")
                arduino.write("Atras,")
            else:
                print("L2 Dropped...")
                arduino.write("Parar,")
                
        if boton.scancode == 291:
            if boton.keystate == 1:
                print("SQUARED Clicked...")
                arduino.write("Izquierda,")
            else:
                print("SQUARED Dropped...")
                arduino.write("Parar,")
                
        if boton.scancode == 289:
            if boton.keystate == 1:
                print("CIRCLE Clicked...")
                arduino.write("Derecha,")
            else:
                print("CIRCLE Dropped...")
                arduino.write("Parar,")
                
        if boton.scancode == 297:
            if boton.keystate == 1:
                print("START Clicked...")
                break
            
print("Conexion completed")
    
        

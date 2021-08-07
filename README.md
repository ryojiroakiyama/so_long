# Description  
Welcome to Dragon Forest!!  
This program allows you to play 2D games using the X server,  
and respects the following rules:
- The W, A, S, and D keys will be used to move the main character.
- Pressing ESC must close the window and quit the program cleanly.
- Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
# Usage  
git clone this repository.  
move to repository you cloned.  
run make.  
after running make, you can see minilibx-linux directory and so_long file.  
- minilibx-linux dirctory  
Libraries for using the X server.
- so_long  
executable file.  

### Let's get started!!  
- mandatory part
```
./so_long map/valid_map/simple1.ber
```
![mandatory](https://user-images.githubusercontent.com/77039327/128588345-b624a1e8-667e-4399-b407-2ad5f2b293fe.gif)

- bonus part  
```
make bonus
./so_long_bonus map/valid_map/simple1.ber
```
![bonus](https://user-images.githubusercontent.com/77039327/128588424-8eb6075e-e26d-4797-a8c2-4fa8d264130a.gif)

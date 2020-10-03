# opens window with text input and button
# pressing the button prints the text in the field in the console

def printInput():
    global e;
    string = e.get();
    print(string);   

import tkinter
root = tkinter.Tk();

e = tkinter.Entry(root);
e.pack();
e.focus_set() # puts keyboard focus on field

b = tkinter.Button(root,text='done!',command=printInput);
b.pack(side='bottom');

root.mainloop();
import CGT

class gugleTranslate :
    def __init__(self,userName) :
        self.userName = userName

    ## This will run C and send the callback funtion pointer
    def runC(self) :
        message = input("What would you like to send to C?\n")
        CGT.translate(self.userName,self.callback,message)

    ## C will call this callback function
    def callback(self,message) :
        print("***PYTHONWORLD***")
        print("Thanks ",userName,"! The callback function received your message from c \"",message,".\"",sep="")

print("***PYTHONWORLD***\nWelcome to Gugle Translate.")
userName = input("Before starting, what is your name?\n")
gt = gugleTranslate(userName)
gt.runC()

## This will execute at the end after C is executed. Since This is C extended embedded Python, C will execute afterwards.
print("***PYTHONWORLD***\nUnwinding Python\nThanks for using Gugle Translate!")


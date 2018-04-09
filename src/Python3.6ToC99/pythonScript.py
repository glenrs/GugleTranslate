import CGT

class gugleTranslate :
    def __init__(self,userName) :
        self.userName = userName

    ## This will run C, it also send a link to the callback function.
    def runC(self) :
        message = input("What would you like to send to C?\n")
        CGT.translate(self.userName,self.callback,message)

    ## This is the callback function that C will call
    def callback(self,message) :
        print("***PYTHONWORLD***")
        print("Thanks ",userName,"! The callback function received your message from c \"",message,"\".",sep="")

print("***PYTHONWORLD***\nWelcome to Gugle Translate.")
userName = input("Before starting, what is your name?\n")
gt = gugleTranslate(userName)
gt.runC()

## This will be the last thing that runs after C finishes executing
print("***PYTHONWORLD***\nUnwinding Python\nThanks for using Gugle Translate!")

        

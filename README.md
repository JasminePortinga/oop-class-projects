# Using GitHub

since i can't seem to change which git credentials i have stored on my laptop i am simply going to have to politely ask you both to not look at my repositories of nonsense (or at least never speak of them to me) when i make commits from my personal account or else i will tank our next project grade on purpose.

anyway, github is where coders keep their repositories of code. you Will use it in your professional life, but some schools don't teach it for some reason. it has kind of a steep learning curve.

![screenshot of github repository](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/1.png)

this is a github repository. notice all the tabs up at the top.

![code / issues / pull requests / actions / projects / wiki](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/2.png)

the only tabs we are going to care about are `code` and `pull requests`. `code` is where you can look at the code, and `pull requests` will be how we share code with one another, through making code branches and merging them when necessary.

![screenshot of the branch switching](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/3.png)

i haven't made any separate branches at the moment because i'm scribbling this together really fast. but how i'd like this to work is that we each have our own separate working branches so that we can make our edits w/o possibly overwriting each other's code.

## cloning the repository

before i get into explaining how branches work, let me first explain how you're supposed to make a local copy of the repository and a couple things i need you to do locally. i use vscode as my coding environment, so that'll be the process i show and explain here, but i poked around in visual studio the other day to figure out how cloning and committing works there too. as long as the changes get committed to github i don't care what ide or procedure you use.

so, assuming that you have [git installed](https://git-scm.com/downloads), make sure it's configured with your github email and username. you'll get a fatal error for how to configure git if you try to commit and sync your code edits otherwise, but the fatal error comes with instructions for how to fix it anyway. 

![aaa](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/4.png)

in vscode, navigate to the squiggly symbol of version control and click on "clone repository". in vscode, this will result in a dropdown that says "clone from github":

![vscode dropdown "clone from github"](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/5.png)


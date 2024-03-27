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

![screenshot of the code dropdown on github](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/6.png)

on github, from the green `<code>` dropdown, copy the "clone using web url" link.

![aaa](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/4.png)

then, in vscode, navigate to the squiggly symbol of version control and click on "clone repository". in vscode, this will result in a dropdown that says "clone from github":

![vscode dropdown "clone from github"](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/5.png)

after you click on it, just paste in the link. it will ask you where you want your repository saved, and remember where you choose to save it, because after you do, i need you to open it up in the file explorer again.

![local file explorer view of the repository. the hidden folder .git and the file .gitignore are boxed in red](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/7.png)

first, make sure you have "hidden items" ticked in the file explorer view tab. then, open `.gitignore` in either an ide or a text editor (it doesn't matter) and then navigate `> .git > info > exclude`:

![//sighs](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/8.png)

open the exclude file in either an ide or regular text editor (it also doesn't matter). copy-paste the contents from `.gitignore` into `exclude`. save `exclude` and close both it and `.gitignore`, since all that does is keep git from tracking and publishing unnecessary files to the github repository.

## creating a branch

idk how this would be done outside of vscode, though you could probably figure out how to do it from github. goodluckhavefun with that. to do it in vscode:

![](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/9.png)

1. click on the squiggly symbol of version control at the BOTTOM of the ide
2. choose "create new branch from..." from the drop-down
3. select "main".

i used my initials to name my branch, but i don't care what you call it. publish it. and ***please** do not stray from it in your ide* from this point on.

![](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/10.png)

## committing code

committing your code is different from saving the file locally. code commits are for when you make some edits to your code and are satisfied with what it is currently doing, and git makes it such that if you want, you can revert to any older commits. commit often and every time the thought of losing your progress strikes fear into your heart. it also lets you view something called "blame" on github, which i think is called that because if someone breaks a bit of code, you can look at who made what edits last and blame them for it.

![](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/11.png)

in vscode, at the squiggly symbol of version control, you can now see this commit box. BRIEFLY explain what you did in the commit message box, then hit "commit & sync" from the dropdown:

![](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/12.png)

(this is what the commit page looks like in visual studio, btw:)

![](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/13.png)

(you open it from under "git" and i'm sure you can figure the rest out from there.)

## merging branches

once you sync your commits to your branch, you will notice something like this back on github.com:

![](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/14.png)

when the time comes to share code, with one of the other group members, click on "compare and pull request", which will take you to this screen:

![](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/15.png)

then if you scroll down, you'll see all your commit messages since the last branch merge and all the files changed and how. anyway, notice the part i circled in red. when merging branches, you are taking the commits from the COMPARE branch and giving its edits to the BASE branch. also notice how this is a one-way process. knowing which branch to merge into when can get kind of complicated as a result, so we'll cross that bridge when we get there, so for now, we'll just assume that all our pull requests will be from *our own edit branch* --> *main branch*

you'll also notice if you scroll down that you can see all the commits you made since the last merge, their brief descriptions, as well as what files got changed and how. anyway, then you hit "create pull request".

![](https://github.com/JasminePortinga/oop-class-projects/blob/main/docs/img/16.png)

unless you guys are editing the same lines of the same files at the same time (which you shouldn't be, unless i mess up coordinating the project), there should be no conflicts between the branches, and you can just merge the pull request like that. if there are conflicts, then i will take care of it when the time arises bc that is my job as group leader.

otherwise that should be everything you need to know to get started with github for now.
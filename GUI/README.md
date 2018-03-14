[![build status](http://ares-mat17.cs.uleth.ca/gitlab/cpsc3720/CodeReviewSpring2018/JaceRiehl/badges/master/build.svg)](http://ares-mat17.cs.uleth.ca/gitlab/cpsc3720/CodeReviewSpring2018/JaceRiehl/commits/master)
[![coverage report](http://ares-mat17.cs.uleth.ca/gitlab/cpsc3720/CodeReviewSpring2018/JaceRiehl/badges/master/coverage.svg)](http://ares-mat17.cs.uleth.ca/gitlab/cpsc3720/CodeReviewSpring2018/JaceRiehl/commits/master)

# Developer Role
1.	Fork the repository of the person that will review your code on GitLab.
   1.	The Reviewer for your code is the person in the table below who is in the “Reviewer” column where you are in the “Developer” column.
   2.	If you do not have access to the reviewer’s repository, please contact either the reviewer or the instructor.
2.	Create a local clone of your fork of the reviewer’s repository.
3.	Copy the files of your Assignment #1 to the locally cloned repository.
   1.	Do not copy the .git directory from your Assignment #1 or you will overwrite the clone’s configuration.
4.	Add and commit the files to your local clone.
5.	Push the changes to your fork of the reviewer’s repository on GitLab.   
6.	Create a merge request from your fork (which should now contain one or more commits for your Assignment #1 files) to the repository of your reviewer.
7.	Address any feedback given by the reviewer until your merge request is approved.
   1.	You will be pushing your changes to your fork. The merge request will update with your changes automatically.

# Reviewer Role
1.	Review the developer’s pull request and provide any feedback to so that the merge request passes the acceptance criteria given below. 
   1.	The goal is for you to have a working copy of Go Fish that you will be able to extend to include the game Cheat.
   2.	You are welcome to request other changes beyond those that would meet the criteria below. However, these requests should not prevent the merge request from finally being accepted.
   3.	Please see the [assignment's FAQ](https://moodle.uleth.ca/201801/mod/page/view.php?id=36334) for other clarifications, or send an email to the instructor.
   4.	If you want the instructor to look at something specific in the code you are reviewing you can use @anvik to call the instructor's attention to it.
2.	Accept the pull request into your repository.

# Areas to Review
The following criteria are to be used for determining if the merge request is acceptable. As different developers will have different personal criteria for what “acceptable” means, this list is intended to give all students common minimum standard to meet.

Comments that address criteria beyond those listed are allowed and encouraged as long as they are constructive and intended to improve the development skills of the developer. However, these cannot be used as a reason to deny the merge request. If in doubt, please discuss with the instructor. 
## Design
*	Does the code follow the Model-View-Controller pattern?
*	Does static analysis pick up any important errors?

## Run-time
*	Do the unit tests pass?
*	Are there significant memory leaks in the program? (leaks in test suite are acceptable)
*	Does the build pass?

## Documentation
*	Is the documentation generated for the system’s interfaces clear and complete?
*	Are the classes, methods, and fields reasonably named?
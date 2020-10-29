# Work Allocation

This file contains the work assigned to each member, so that everyone gets almost the same opportunity to learn.

---

The core of this project relies on version control system, which would be interacted safely with using a wrapper written in C++ so that we can easily call the functions in a failsafe manner, which does not affect the stability of the system.

## Stability of System

The main aim of this experiment is to ensure stability in systems, and if this project is not stable in itself, there is no way we can ensure stability or healing nature of the operating system we are running this utility upon.

## Wrapper for GIT actions

The module must have the following features.

- Basic git commands for commit, logs, branch, checkout, pull, push.
- Result of commands must be returned in form of an object, or a structure, and not simply a string containing everything so that other components of the utility can use the data.

## Watcher

This module has the following features. All commands are executed pass through the watcher.

**Flow**

` user -> opens utility -> enters command -> command goes to watcher -> watcher adds entry to logs -> executes -> shows output to user`

Watcher is responsible for commands which user enters to access our features. For example, user enters the following commands and all this happens.

```bash
ls
# system command runs, returns output

mkdir dir1
# directory created

:checkpoint create
# this would  invoke an internal function (watcher does this, just calling that function) which in turn does whats' required. For instance, in this example, it creates a checkpoint in the system timeline.

:checkpoint revert
# this would take system to last known checkpoint
```

Note that the commands that the watcher identifies would be provided as a Array<string>, and the implementation of such commands is not part of watcher. Watcher only calls the functions responsible for the actions.

## Log Writer

All Actions done on/via any component are logged with all details, everything that user enters, with timestamps, sequentially, are written to a log file. The log file is not a simple text file, but a binary file which stores / objects so that logs can be readed and parsed back into original format easily.

Requested Features :

- Category wise logging
- Ability to export logs to simple.txt file
- Callable functions which can be used by other modules
- Any other feature that you think is required

```dotnetcli
ls
:checkpoint create
# generates the following log entry
[
    {
      category: COMMAND_SYSTEM,
      rawCommand: "ls",
      timeStamp: 1600671076,
    },
    {
      category: COMMAND_UTILITY,
      rawCommand: "checkpoint create",
      timeStamp: 1600671076
    }
]
```

## Utility Core

Utility core is the library written on top of the **_git actions library_** (first one mentioned on this page). This library provides the final callable methods that the **watchman** calls. All internal commands that the utility provides are implemented in the core library itself.

The target is to have simple functions like

```cpp
// create a new
worker.createNewCheckpoint();
worker.revertLastCheckpoint();
worker.newWorkSpace();
worker.changeWorkSpace(3);
worker.integrateWorkSpace(3);
```

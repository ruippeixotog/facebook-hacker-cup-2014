# Solutions to Facebook Hacker Cup 2014 problems

This repository contains solutions to the [Facebook Hacker Cup 2014][1] problems. These solutions are provided "as is". I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and id of the problem you want to compile (see section "Problems Solved" for the list of possible ids):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the id of the desired problem:

    $ ./<problem_id>

Some of the problems have an alternative version written in [Scala][2]. A [sbt][3] launch script that allows users to quickly compile and run Scala source code, without the need to have anything installed other than a standard Java compiler, is provided. You can run any Scala solution by issuing the following command in the repository root directory:

    $ ./sbt run

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem id is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete and/or aren't efficient enough.

### Qualification Round

* ✓ [20: Square Detector][qual1] (`square-detector`)
* ✗ [35: Basketball Game][qual2] (`basketball-game`)
* ✓ [45: Tennison][qual3] (`tennison`) [only Scala version is correct]

[1]: https://www.facebook.com/hackercup
[2]: http://www.scala-lang.org
[3]: http://www.scala-sbt.org
[qual1]: https://www.facebook.com/hackercup/problems.php?pid=318555664954399&round=598486203541358
[qual2]: https://www.facebook.com/hackercup/problems.php?pid=740733162607577&round=598486203541358
[qual3]: https://www.facebook.com/hackercup/problems.php?pid=373965339404375&round=598486203541358

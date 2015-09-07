# Facebook Hacker Cup 2014

This repository contains my solutions to the problems from [Facebook Hacker Cup 2014][1] problems. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Some of the problems have an alternative version written in [Scala][2]. A [sbt][3] launch script that allows users to quickly compile and run Scala source code, without the need to have anything installed other than a standard Java compiler, is provided. You can run any Scala solution by issuing the following command in the repository root directory:

    $ ./sbt run

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [20: Square Detector][qual1] (`square-detector`)
* ✓ [35: Basketball Game][qual2] (`basketball-game`)
* ✓ [45: Tennison][qual3] (`tennison`) [only the Scala version has the required precision]

### Round 1

* ✓ [15: Labelmaker][round11] (`labelmaker`)
* ✗ [20: Coins Game][round12] (`coins-game`)
* ✓ [25: AAAAAA][round13] (`aaaaaa`)
* ✗ [40: Preventing Alzheimer's][round14] (`preventing-alzheimers`)

### Round 2

* ✗ [25: Magic Pairs][round21] (`magic-pairs`)

[1]: https://www.facebook.com/hackercup
[2]: http://www.scala-lang.org
[3]: http://www.scala-sbt.org
[qual1]: https://www.facebook.com/hackercup/problems.php?pid=318555664954399&round=598486203541358
[qual2]: https://www.facebook.com/hackercup/problems.php?pid=740733162607577&round=598486203541358
[qual3]: https://www.facebook.com/hackercup/problems.php?pid=373965339404375&round=598486203541358
[round11]: https://www.facebook.com/hackercup/problems.php?pid=637270059647812&round=1437956993099239
[round12]: https://www.facebook.com/hackercup/problems.php?pid=105395349584705&round=1437956993099239
[round13]: https://www.facebook.com/hackercup/problems.php?pid=184326661771870&round=1437956993099239
[round14]: https://www.facebook.com/hackercup/problems.php?pid=1420024724897316&round=1437956993099239
[round21]: https://www.facebook.com/hackercup/problems.php?pid=620734011349888&round=544142832342014

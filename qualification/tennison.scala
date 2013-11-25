import java.io.{PrintStream, File}
import java.util.{Locale, Scanner}
import scala.math._

object Tennison extends App {

  Locale.setDefault(Locale.US)
  val sc = new Scanner(System.in)

  val MAXP = 1000

  @inline def wif(p: Int, vthen: BigDecimal, velse: BigDecimal) =
    (p * vthen + (MAXP - p) * velse) / MAXP

  val t = sc.nextInt()
  (1 to t).foreach { tc =>
    val k = sc.nextInt()
    val ps, pr, pi, pu, pw, pd, pl: BigDecimal = sc.nextBigDecimal()
    val ipu = (pu * MAXP).toInt
    val ipd = (pd * MAXP).toInt

    val pres = Array.fill[BigDecimal](k + 1, k + 1, MAXP + 1)(0)
    pres(0)(0)((pi * MAXP).toInt) = 1

    for(i <- 0 until k; j <- 0 until k; psun <- 0 to MAXP if pres(i)(j)(psun) > 0) {

      val pwin = pres(i)(j)(psun) * wif(psun, ps, pr)
      if(pwin > 0) {
        pres(i + 1)(j)(min(psun + ipu, MAXP)) += pwin * pw
        pres(i + 1)(j)(psun) += pwin * (1 - pw)
      }

      val plose = pres(i)(j)(psun) - pwin
      if(plose > 0) {
       pres(i)(j + 1)(max(psun - ipd, 0)) += plose * pl
       pres(i)(j + 1)(psun) += plose * (1 - pl)
      }
    }
    val total = (0 until k).map(pres(k)).map(_.sum).sum
    println("Case #%d: %.6f".format(tc, total))
  }
}

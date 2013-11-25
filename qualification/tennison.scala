import java.io.{PrintStream, File}
import java.util.{Locale, Scanner}

object Tennison extends App {

  Locale.setDefault(Locale.US)
  val sc = new Scanner(new File("f.in"))
  val fout = new PrintStream("f.out")

  @inline def wif(p: BigDecimal, vthen: BigDecimal, velse: BigDecimal) =
    p * vthen + (1 - p) * velse

  val t = sc.nextInt()
  (1 to t).foreach { tc =>
    val k = sc.nextInt()
    val ps, pr, pi, pu, pw, pd, pl = sc.nextBigDecimal()

    val pres = Array.fill[BigDecimal](k + 1, k + 1)(0)
    val psun = Array.fill[BigDecimal](k + 1, k + 1)(0)
    pres(0)(0) = 1
    psun(0)(0) = pi

    for(i <- 0 until k; j <- 0 until k if pres(i)(j) > 0) {
      val wpsun = psun(i)(j) / pres(i)(j)

      val pwin = pres(i)(j) * wif(wpsun, ps, pr)
      if(pwin > 0) {
        psun(i + 1)(j) += pwin * wif(pw, (wpsun + pu) min 1, wpsun)
        pres(i + 1)(j) += pwin
      }

      val plose = pres(i)(j) * (1 - wif(wpsun, ps, pr))
      if(plose > 0) {
       psun(i)(j + 1) += plose * wif(pl, (wpsun - pd) max 0, wpsun)
       pres(i)(j + 1) += plose
      }
    }
    val total = (0 until k).map(pres(k)).sum
    System.err.println(total)
    fout.println("Case #%d: %.6f".format(tc, total))
  }

  sc.close()
}

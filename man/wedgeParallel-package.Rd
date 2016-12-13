\name{wedgeParallel-package}
\alias{wedgeParallel-package}
\encoding{UTF-8}

\docType{package}
\title{
\packageTitle{wedgeParallel}
}
\description{
\packageDescription{wedgeParallel}
}
\details{

The DESCRIPTION file:
\packageDESCRIPTION{wedgeParallel}
\packageIndices{wedgeParallel}
~~ An overview of how to use the package, including the most important ~~
~~ functions ~~
}
\author{
\packageAuthor{wedgeParallel}

Maintainer: \packageMaintainer{wedgeParallel}
}
\references{
B. Ycart (2016) Computing wedge probabilities. Arxiv #16??.????
}
\keyword{distribution}
\examples{
# random wedges
a1 <- 10*runif(10^6)^2
b1 <- 10*runif(10^6)^2
a2 <- 10*runif(10^6)^2
b2 <- 10*runif(10^6)^2
# wedge probabilities, 3 term approximation
pw3 <- wedge(a1,b1,a2,b2)
}

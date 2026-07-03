#include "utilities.hpp"

#include "doctest.h"

TEST_CASE("Function stringToInt") {
  CHECK(nc::stringToInt("1234", "a1") == 1234);
  CHECK(nc::stringToInt("00", "a2") == 0);
  CHECK_THROWS_WITH(nc::stringToInt("123a", "b"),
                    "valore in input non valido: b");
  CHECK_THROWS_WITH(nc::stringToInt("!234", "c"),
                    "valore in input non valido: c");
  CHECK_THROWS_WITH(nc::stringToInt("1234567890123456", "d"),
                    "valore in input fuori dal limite: d");
  CHECK_THROWS_WITH(nc::stringToInt("", "e"), "valore in input non valido: e");
  CHECK_THROWS(nc::stringToInt("1.2", "g"));
}

TEST_CASE("Function stringToDouble") {
  CHECK(nc::stringToDouble("-1", "a1") == doctest::Approx(-1.));
  CHECK(nc::stringToDouble(".34", "a2") == doctest::Approx(.34));
  CHECK_THROWS_WITH(nc::stringToDouble("1.a", "b"),
                    "valore in input non valido: b");
  CHECK_THROWS_WITH(nc::stringToDouble("a.2", "c"),
                    "valore in input non valido: c");
  CHECK_THROWS_WITH(nc::stringToDouble("9999.9999e999", "d"),
                    "valore in input fuori dal limite: d");
  CHECK_THROWS_WITH(nc::stringToDouble("", "e"),
                    "valore in input non valido: e");
  CHECK_THROWS_WITH(nc::stringToDouble("asdf", "f"),
                    "valore in input non valido: f");
}

TEST_CASE("Function stringToSize_t") {
  CHECK(nc::stringToSize_t("1234", "a1") == size_t(1234));
  CHECK_THROWS(nc::stringToSize_t("1.2", "b"));
  CHECK_THROWS_WITH(nc::stringToSize_t("a12", "c"),
                    "valore in input non valido: c");
  CHECK_THROWS_WITH(nc::stringToSize_t("999999999999999999999", "d"),
                    "valore in input fuori dal limite: d");
  CHECK_THROWS_WITH(nc::stringToSize_t("", "e"),
                    "valore in input non valido: e");
  CHECK_THROWS_WITH(nc::stringToSize_t("asdf", "f"),
                    "valore in input non valido: f");
}
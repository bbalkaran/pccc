// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins(cpp11)]]

#include <string>
#include <Rcpp.h>
#include "pccc.h"

// [[Rcpp::export]]
Rcpp::List get_codes(int version = 9) {
  codes cds(version);
  return Rcpp::List::create(
      Rcpp::Named("version")            = cds.get_version(),
      Rcpp::Named("dx") = 
        Rcpp::List::create( 
          Rcpp::Named("neuromusc")       = Rcpp::wrap(cds.get_dx_neuromusc()),
          Rcpp::Named("cvd")             = Rcpp::wrap(cds.get_dx_cvd()),
          Rcpp::Named("respiratory")     = Rcpp::wrap(cds.get_dx_respiratory()),
          Rcpp::Named("renal")           = Rcpp::wrap(cds.get_dx_renal()),
          Rcpp::Named("gi")              = Rcpp::wrap(cds.get_dx_gi()),
          Rcpp::Named("hemato_immu")     = Rcpp::wrap(cds.get_dx_hemato_immu()),
          Rcpp::Named("metabolic")       = Rcpp::wrap(cds.get_dx_metabolic()),
          Rcpp::Named("congeni_genetic") = Rcpp::wrap(cds.get_dx_congeni_genetic()),
          Rcpp::Named("malignancy")      = Rcpp::wrap(cds.get_dx_malignancy()),
          Rcpp::Named("neonatal")        = Rcpp::wrap(cds.get_dx_neonatal()),
          Rcpp::Named("tech_dep")        = Rcpp::wrap(cds.get_dx_tech_dep()),
          Rcpp::Named("transplant")      = Rcpp::wrap(cds.get_dx_transplant())),
      Rcpp::Named("pc") =
        Rcpp::List::create(
           Rcpp::Named("neuromusc")       = Rcpp::wrap(cds.get_pc_neuromusc()),
           Rcpp::Named("cvd")             = Rcpp::wrap(cds.get_pc_cvd()),
           Rcpp::Named("respiratory")     = Rcpp::wrap(cds.get_pc_respiratory()),
           Rcpp::Named("renal")           = Rcpp::wrap(cds.get_pc_renal()),
           Rcpp::Named("gi")              = Rcpp::wrap(cds.get_pc_gi()),
           Rcpp::Named("hemato_immu")     = Rcpp::wrap(cds.get_pc_hemato_immu()),
           Rcpp::Named("metabolic")       = Rcpp::wrap(cds.get_pc_metabolic()),
           Rcpp::Named("malignancy")      = Rcpp::wrap(cds.get_pc_malignancy()),
           Rcpp::Named("tech_dep")        = Rcpp::wrap(cds.get_pc_tech_dep()),
           Rcpp::Named("transplant")      = Rcpp::wrap(cds.get_pc_transplant()))
      );
}

// [[Rcpp::export]]
Rcpp::NumericVector ccc_rcpp(std::vector<std::string>& dx, std::vector<std::string>& pc, int version = 9)
{ 
  codes cdv(version);

  int neuromusc       = cdv.neuromusc(dx, pc);
  int cvd             = cdv.cvd(dx, pc);
  int respiratory     = cdv.respiratory(dx, pc);
  int renal           = cdv.renal(dx, pc);
  int gi              = cdv.gi(dx, pc);
  int hemato_immu     = cdv.hemato_immu(dx, pc);
  int metabolic       = cdv.metabolic(dx, pc);
  int congeni_genetic = cdv.congeni_genetic(dx);
  int malignancy      = cdv.malignancy(dx, pc);
  int neonatal        = cdv.neonatal(dx);
  int tech_dep        = cdv.tech_dep(dx, pc);
  int transplant      = cdv.transplant(dx, pc);

  return Rcpp::NumericVector::create(
      Rcpp::Named("neuromusc")       = neuromusc,
      Rcpp::Named("cvd")             = cvd,
      Rcpp::Named("respiratory")     = respiratory,
      Rcpp::Named("renal")           = renal,
      Rcpp::Named("gi")              = gi,
      Rcpp::Named("hemato_immu")     = hemato_immu,
      Rcpp::Named("metabolic")       = metabolic,
      Rcpp::Named("congeni_genetic") = congeni_genetic,
      Rcpp::Named("malignancy")      = malignancy,
      Rcpp::Named("tech_dep")        = tech_dep,
      Rcpp::Named("transplant")      = transplant
      ); 
}

//Rcpp::NumericMatrix ccc_mat(Rcpp::NumericMatrix& dxmat, Rcpp::NumericMatrix& pcmat, int version = 9)
//{ 
//  codes cdv(version);
//
//  if (dxmat.rows() != pcmat.rows()) {
//    ::Rf_error("number of rows for dxmat and pcmat need to be equal.");
//  }
//
//  Rcpp::NumericMatrix out(dxmat.rows(), 12);
//
//  for (int i = 0; i < out.rows(); ++i) {
//    out.row(i) = ccc_rcpp(Rcpp::as<std::vector<std::string>>(dxmat.row(i)), Rcpp::as<std::vector<std::string>>(pcmat.row(i)), version);
//  }
//
//  return out; 
//}
// ====================================================================
// This file is part of FlexibleSUSY.
//
// FlexibleSUSY is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// FlexibleSUSY is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with FlexibleSUSY.  If not, see
// <http://www.gnu.org/licenses/>.
// ====================================================================

// File generated at Thu 12 Oct 2017 13:57:41

/**
 * @file MSSM_mAmu_two_scale_model.cpp
 * @brief implementation of the MSSM_mAmu model class
 *
 * Contains the definition of the MSSM_mAmu model class methods
 * which solve EWSB and calculate pole masses and mixings from DRbar
 * parameters.
 *
 * This file was generated at Thu 12 Oct 2017 13:57:41 with FlexibleSUSY
 * 2.0.0 (git commit: unknown) and SARAH 4.11.0 .
 */

#include "MSSM_mAmu_two_scale_model.hpp"

namespace flexiblesusy {

#define CLASSNAME MSSM_mAmu<Two_scale>

CLASSNAME::MSSM_mAmu(const MSSM_mAmu_input_parameters& input_)
   : MSSM_mAmu_mass_eigenstates(input_)
{
}

void CLASSNAME::calculate_spectrum()
{
   MSSM_mAmu_mass_eigenstates::calculate_spectrum();
}

void CLASSNAME::clear_problems()
{
   MSSM_mAmu_mass_eigenstates::clear_problems();
}

std::string CLASSNAME::name() const
{
   return MSSM_mAmu_mass_eigenstates::name();
}

void CLASSNAME::run_to(double scale, double eps)
{
   MSSM_mAmu_mass_eigenstates::run_to(scale, eps);
}

void CLASSNAME::print(std::ostream& out) const
{
   MSSM_mAmu_mass_eigenstates::print(out);
}

void CLASSNAME::set_precision(double p)
{
   MSSM_mAmu_mass_eigenstates::set_precision(p);
}

std::ostream& operator<<(std::ostream& ostr, const MSSM_mAmu<Two_scale>& model)
{
   model.print(ostr);
   return ostr;
}

} // namespace flexiblesusy

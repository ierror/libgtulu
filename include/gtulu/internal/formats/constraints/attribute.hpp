/**
 * @file
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
 *
 * @date 19 déc. 2009
 * @todo comment
 */

#ifndef GTULU_INTERNAL_FORMAT_CONSTRAINT_ATTRIBUTE_HPP_
#define GTULU_INTERNAL_FORMAT_CONSTRAINT_ATTRIBUTE_HPP_

#include "gtulu/internal/formats/attribute.hpp"
#include "gtulu/internal/formats/data.hpp"

#include <boost/mpl/not.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/and.hpp>

namespace gtulu {
  namespace internal {
    namespace bm = ::boost::mpl;

    namespace formats {
      namespace attribute {

        template< typename AttributeFormat, typename DataFormat >
        struct data_packing_check {
            typedef fc::packing::is_one_in_one< DataFormat > is_one_in_one_packed;
            typedef fc::packing::is_four_in_one< DataFormat > is_four_in_one_packed;
            typedef fc::cardinality::is_four< AttributeFormat > is_four_elements;

            typedef bm::and_< bm::not_< is_one_in_one_packed >, bm::not_< is_four_in_one_packed > > is_not_one_or_four_packed;
            typedef bm::and_< is_four_in_one_packed, bm::not_< is_four_elements > > is_packed_but_not_four_elements;
            typedef bm::and_<
                is_four_in_one_packed,
                bm::and_<
                    bm::not_< fdf::is_gl_unsigned_int_2_10_10_10_rev< DataFormat >,
                        fdf::is_gl_int_2_10_10_10_rev< DataFormat > > > > is_packed_but_not_2_10_10_10;

            typedef bm::and_< bm::not_< is_not_one_or_four_packed >, bm::not_< is_packed_but_not_four_elements >,
                bm::not_< is_packed_but_not_2_10_10_10 > > type;

            static_assert(type::value, "AttributeFormat is not compatible with DataFormat");
            static_assert(type::value, "");
            static_assert(type::value, "  [2.8 Vertex Arrays]");
            static_assert(is_not_one_or_four_packed::value, "  - AttributeFormat requires one- or four-packed data and DataFormat is not.");
            static_assert(is_packed_but_not_four_elements::value, "  - DataFormat is packed but AttributeFormat doesn't have four elements.");
            static_assert(is_packed_but_not_2_10_10_10::value, "  - DataFormat is packed but is not gl_unsigned_int_2_10_10_10_rev or gl_int_2_10_10_10_rev.");
        };

        template< typename AttributeFormat, typename DataFormat >
        struct data_type_check {
            typedef fcn::integral::is_floating< typename fc::get_numeric< AttributeFormat >::type > floating_check;
            typedef bm::and_< fc::integral::is_integral< DataFormat >, fc::integral::is_integral< AttributeFormat > > integer_check;

            typedef bm::or_< floating_check, integer_check > type;
            static_assert(type::value, "AttributeFormat is not compatible with DataFormat, integer attribute formats require integer data, only floating attribute formats can be used with any data format types.");
        };

        template< typename AttributeFormat, typename DataFormat >
        struct is_data_compatible {
            typedef typename data_type_check< AttributeFormat, DataFormat >::type data_type_c;
            typedef typename data_packing_check< AttributeFormat, DataFormat >::type data_packing_c;

            typedef bm::and_< data_type_c, data_packing_c > type;
        };

      } // namespace attribute
    } // namespace formats

  } // namespace internal
} // namespace gtulu

#endif /* GTULU_INTERNAL_FORMAT_CONSTRAINT_ATTRIBUTE_HPP_ */

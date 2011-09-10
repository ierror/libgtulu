/**
 * @file
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
 *
 * @date 19 déc. 2009
 * @todo comment
 */

#ifndef IN_GTULU_INTERNAL_UNIFORM_HPP_
#error "gtulu/internal/uniform/uniform_vector.hpp should not be included directly, please include gtulu/internal/uniform.hpp instead."
#endif /* IN_GTULU_INTERNAL_UNIFORM_HPP_ */

#ifndef GTULU_INTERNAL_UNIFORM_VECTOR_HPP_
#define GTULU_INTERNAL_UNIFORM_VECTOR_HPP_

#include "gtulu/internal/formats/conversions/dimension.hpp"

#include <boost/preprocessor/repetition/enum_params.hpp>

namespace gtulu {
  namespace internal {

    namespace uniform {
      namespace vector {

        template< typename DataType, typename Count >
        struct uniform_binder;

#define DECLARE_BINDER(type_m, count_m) \
      template< > \
      struct uniform_binder< fut::type_m, fc::to_typename< count_m >::type > { \
          inline static void bind(location_t const location_in, BOOST_PP_ENUM_PARAMS(count_m, fu::to_typename< fut::type_m >::type const value_in)) { \
            fnc:: gl_uniform_##count_m ::call(location_in, BOOST_PP_ENUM_PARAMS(count_m, value_in)); \
          } \
          inline static void bind(location_t const location_in, ::std::uint32_t const number_in, fu::to_typename< fut::type_m >::type const* values_in) { \
            fnc:: gl_uniform_##count_m ::call(location_in, number_in, values_in); \
          } \
      };

#define DECLARE_VECTOR_BINDER(type_m) \
        DECLARE_BINDER(type_m, 2) \
        DECLARE_BINDER(type_m, 3) \
        DECLARE_BINDER(type_m, 4)

        DECLARE_VECTOR_BINDER(floating)
        DECLARE_VECTOR_BINDER(integer)
        DECLARE_VECTOR_BINDER(unsigned_integer)
        DECLARE_VECTOR_BINDER(boolean)

#undef DECLARE_VECTOR_BINDER
#undef DECLARE_BINDER

        template< typename Format, typename BinderType = uniform_binder< typename Format::info::type,
            typename Format::info::count >
            , typename ValueType = typename fu::to_typename< typename Format::info::type >::type >
        struct uniform {
            typedef Format format;
            typedef ValueType value_type;
            typedef BinderType binder;
        };
      } // namespace vector

#define DECLARE_UNIFORM_VECTOR(format_m) \
    typedef vector::uniform< fu::format_m > format_m;

      DECLARE_UNIFORM_VECTOR(gl_float_vec2)
      DECLARE_UNIFORM_VECTOR(gl_float_vec3)
      DECLARE_UNIFORM_VECTOR(gl_float_vec4)
      DECLARE_UNIFORM_VECTOR(gl_int_vec2)
      DECLARE_UNIFORM_VECTOR(gl_int_vec3)
      DECLARE_UNIFORM_VECTOR(gl_int_vec4)
      DECLARE_UNIFORM_VECTOR(gl_unsigned_int_vec2)
      DECLARE_UNIFORM_VECTOR(gl_unsigned_int_vec3)
      DECLARE_UNIFORM_VECTOR(gl_unsigned_int_vec4)
      DECLARE_UNIFORM_VECTOR(gl_bool_vec2)
      DECLARE_UNIFORM_VECTOR(gl_bool_vec3)
      DECLARE_UNIFORM_VECTOR(gl_bool_vec4)

#undef DECLARE_UNIFORM_VECTOR

    } // namespace uniform

    namespace giuv = ::gtulu::internal::uniform::vector;

  } // namespace internal
} // namespace gtulu

#endif /* GTULU_INTERNAL_UNIFORM_VECTOR_HPP_ */
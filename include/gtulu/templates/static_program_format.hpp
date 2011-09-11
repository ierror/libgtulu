// #template#<format>_program_tpl,_author_tpl,_date_tpl
/**
 * @file
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE or copy at http://www.boost.org/LICENSE
 */

#ifndef GTULU_PROGRAM_FORMAT_program_upper_tpl_HPP_
#define GTULU_PROGRAM_FORMAT_program_upper_tpl_HPP_

#include <gtulu/opengl.hpp>
#include <gtulu/internal/format/shader/static.hpp>
#include <gtulu/internal/format/program/static.hpp>
#include <gtulu/internal/uniform.hpp>
#include <gtulu/internal/attribute.hpp>
#include <gtulu/internal/object/shader.hpp>
#include <gtulu/internal/object/program.hpp>
#include <gtulu/internal/object/vertexarray.hpp>
#include <gtulu/internal/object/framebuffer.hpp>
#include <gtulu/internal/object/framebuffer/attacher.hpp>
#include <gtulu/internal/object/framebuffer/format.hpp>
#include <gtulu/internal/object/texture.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/preprocessor.hpp>

namespace gtulu {
  namespace internal {

    namespace format {
      namespace program {

        class _program_tpl_program_format: public fp::static_program_format {
          protected:
            // #template#<define_shader>_shader_tpl,_type_tpl
            class _shader_tpl__type_tpl_shader_format: public fs::static_shader_format< fst::gl__type_tpl > {
              protected:
                static char const* source;

              public:
                _shader_tpl__type_tpl_shader_format() :
                    fs::static_shader_format< fst::gl__type_tpl >() {
                  set_source(get_source());

                  shader_base::compile();
                }

                char const* get_source() const {
                  return _shader_tpl__type_tpl_shader_format::source;
                }
            };

            typedef gio::shader< _shader_tpl__type_tpl_shader_format > _shader_tpl__type_tpl_shader_t;
            // #template#</define_shader>
          public:
            _program_tpl_program_format() {
              // #template#<declare_shader>_shader_tpl,_type_tpl
              _shader_tpl__type_tpl_shader_t _shader_tpl__type_tpl_shader;
              attach(_shader_tpl__type_tpl_shader);
              // #template#</declare_shader>

              link();
            }

            // #template#<uniform>_name_tpl,_type_tpl,_location_tpl,_size_tpl
            typedef giu::gl__type_tpl::binder _name_tpl_binder_t;
            typedef giu::gl__type_tpl::value_type _name_tpl_value_t;

            void set__name_tpl(BOOST_PP_ENUM_PARAMS(_size_tpl, _name_tpl_value_t const _name_tpl_in)) {
              gio::program_base::bind();
              _name_tpl_binder_t::bind(_location_tpl, BOOST_PP_ENUM_PARAMS(_size_tpl, _name_tpl_in));
            }
            // #template#</uniform>

            // #template#<uniform_sampler>_name_tpl,_type_tpl,_location_tpl
            typedef giu::gl__type_tpl::binder _name_tpl_binder_t;
            typedef giu::gl__type_tpl::value_type _name_tpl_value_t;

            template< typename TextureFormat >
            void set__name_tpl(gio::texture< TextureFormat > const& value_in) {
              gio::program_base::bind();
              _name_tpl_binder_t::bind(_location_tpl, value_in);
            }
            // #template#</uniform_sampler>

            // #template#<uniform_array>_name_tpl,_type_tpl,_location_tpl,_size_tpl,_count_tpl
            typedef giu::gl__type_tpl::binder _name_tpl_binder_t;
            typedef giu::gl__type_tpl::value_type _name_tpl_value_t;

            void set__name_tpl(_name_tpl_value_t const values_in[_size_tpl * _count_tpl]) {gio::program_base::bind();
            _name_tpl_binder_t::bind(_location_tpl, _count_tpl, values_in);
          }
          // #template#</uniform_array>

          template< typename DrawableType = gio::drawable const& >
          struct framebuffer_format: public gio::framebuffer_base, public gif::framebuffer_format_base< DrawableType > {
            // #template#<output>_name_tpl,_type_tpl,_location_tpl,_index_tpl
            template< typename TemporaryFramebufferSlot = gif::draw_framebuffer_slot, typename NewDrawableType >
            void set__name_tpl(NewDrawableType const& drawable_in) {
              gio::framebuffer_base::bind< TemporaryFramebufferSlot >();
              gif::framebuffer_format_base< DrawableType >::template set<
              typename TemporaryFramebufferSlot::slot_type >(_location_tpl, drawable_in);
            }
            // #template#</output>

            // #template#<output_array>_name_tpl,_type_tpl,_location_tpl,_index_tpl,_size_tpl
            // #template#</output_array>
          };

          typedef gio::framebuffer< framebuffer_format< > > framebuffer_t;
          ::boost::shared_ptr< framebuffer_t > new_framebuffer() const {
            return ::boost::shared_ptr< framebuffer_t >(new framebuffer_t());
          }

          typedef gio::default_framebuffer< framebuffer_format< const gio::default_drawable > > default_framebuffer_t;
          ::boost::shared_ptr< default_framebuffer_t > get_default_framebuffer() const {
            return ::boost::shared_ptr< default_framebuffer_t >(new default_framebuffer_t());
          }

          struct vertex_array_format: public gio::vertexarray_base, public gid::drawable {
            template< typename DrawingMode = gidm::gl_triangles >
            inline void draw(gio::program< _program_tpl_program_format > const& program_in,
                ::std::uint32_t const start_in,
                ::std::uint32_t const count_in,
                ::std::uint32_t const instance_count_in = 1) {
              draw< DrawingMode > (program_in,
                  *program_in.get_default_framebuffer(),
                  start_in,
                  count_in,
                  instance_count_in);
            }

            template< typename DrawingMode = gidm::gl_triangles >
            inline void draw_multiple(gio::program< _program_tpl_program_format > const& program_in,
                ::std::uint32_t const starts_in[],
                ::std::uint32_t const counts_in[],
                ::std::size_t const count_in) {
              draw_multiple< DrawingMode > (program_in,
                  *program_in.get_default_framebuffer(),
                  starts_in,
                  counts_in,
                  count_in);
            }

            template< typename DrawingMode = gidm::gl_triangles, typename BufferFormat,
            typename BufferUsage >
            inline void draw(gio::program< _program_tpl_program_format > const& program_in,
                gio::buffer< BufferFormat, BufferUsage > const& buffer_in,
                ::std::uint32_t const count_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const instance_count_in = 1,
                ::std::uint32_t const base_vertex_in = 0) {
              draw< DrawingMode > (program_in,
                  *program_in.get_default_framebuffer(),
                  buffer_in,
                  count_in,
                  offset_in,
                  instance_count_in,
                  base_vertex_in);
            }

            template< typename DrawingMode = gidm::gl_triangles, typename BufferFormat,
            typename BufferUsage >
            inline void draw_range(gio::program< _program_tpl_program_format > const& program_in,
                gio::buffer< BufferFormat, BufferUsage > const& buffer_in,
                ::std::uint32_t const count_in,
                ::std::uint32_t const min_index_in,
                ::std::uint32_t const max_index_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const base_vertex_in = 0) {
              draw_range< DrawingMode > (program_in,
                  *program_in.get_default_framebuffer(),
                  buffer_in,
                  count_in,
                  min_index_in,
                  max_index_in,
                  offset_in,
                  base_vertex_in);
            }

            template< typename DrawingMode = gidm::gl_triangles, typename BufferFormat,
            typename BufferUsage >
            inline void draw_multiple(gio::program< _program_tpl_program_format > const& program_in,
                gio::buffer< BufferFormat, BufferUsage > const& buffer_in,
                ::std::uint32_t const counts_in[],
                ::std::uint32_t const offsets_in[],
                ::std::size_t const count_in) {
              draw_multiple< DrawingMode > (program_in,
                  *program_in.get_default_framebuffer(),
                  buffer_in,
                  counts_in,
                  offsets_in,
                  count_in);
            }

            template< typename DrawingMode = gidm::gl_triangles >
            inline void draw(gio::program< _program_tpl_program_format > const& program_in,
                gio::framebuffer_base const& framebuffer_in,
                ::std::uint32_t const start_in,
                ::std::uint32_t const count_in,
                ::std::uint32_t const instance_count_in = 1) {
              program_in.bind();
              framebuffer_in.bind< gif::draw_framebuffer_slot > ();
              gio::vertexarray_base::bind();
              gid::drawable::draw< DrawingMode >(start_in, count_in, instance_count_in);
            }

            template< typename DrawingMode = gidm::gl_triangles >
            inline void draw_multiple(gio::program< _program_tpl_program_format > const& program_in,
                gio::framebuffer_base const& framebuffer_in,
                ::std::uint32_t const starts_in[],
                ::std::uint32_t const counts_in[],
                ::std::size_t const count_in) {
              program_in.bind();
              framebuffer_in.bind< gif::draw_framebuffer_slot > ();
              gio::vertexarray_base::bind();
              gid::drawable::draw< DrawingMode >(starts_in, counts_in, count_in);
            }

            template< typename DrawingMode = gidm::gl_triangles, typename BufferFormat,
            typename BufferUsage >
            inline void draw(gio::program< _program_tpl_program_format > const& program_in,
                gio::framebuffer_base const& framebuffer_in,
                gio::buffer< BufferFormat, BufferUsage > const& buffer_in,
                ::std::uint32_t const count_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const instance_count_in = 1,
                ::std::uint32_t const base_vertex_in = 0) {
              program_in.bind();
              framebuffer_in.bind< gif::draw_framebuffer_slot > ();
              gio::vertexarray_base::bind();
              gid::drawable::draw< DrawingMode >(buffer_in,
                  count_in,
                  offset_in,
                  instance_count_in,
                  base_vertex_in);
            }

            template< typename DrawingMode = gidm::gl_triangles, typename BufferFormat,
            typename BufferUsage >
            inline void draw_range(gio::program< _program_tpl_program_format > const& program_in,
                gio::framebuffer_base const& framebuffer_in,
                gio::buffer< BufferFormat, BufferUsage > const& buffer_in,
                ::std::uint32_t const count_in,
                ::std::uint32_t const min_index_in,
                ::std::uint32_t const max_index_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const base_vertex_in = 0) {
              program_in.bind();
              framebuffer_in.bind< gif::draw_framebuffer_slot > ();
              gio::vertexarray_base::bind();
              gid::drawable::draw< DrawingMode >(buffer_in,
                  count_in,
                  min_index_in,
                  max_index_in,
                  offset_in,
                  base_vertex_in);
            }

            template< typename DrawingMode = gidm::gl_triangles, typename BufferFormat,
            typename BufferUsage >
            inline void draw_multiple(gio::program< _program_tpl_program_format > const& program_in,
                gio::framebuffer_base const& framebuffer_in,
                gio::buffer< BufferFormat, BufferUsage > const& buffer_in,
                ::std::uint32_t const counts_in[],
                ::std::uint32_t const offsets_in[],
                ::std::size_t const count_in) {
              program_in.bind();
              framebuffer_in.bind< gif::draw_framebuffer_slot > ();
              gio::vertexarray_base::bind();
              gid::drawable::draw< DrawingMode >(buffer_in, counts_in, offsets_in, count_in);
            }

            // #template#<attribute>_name_tpl,_type_tpl,_location_tpl,_size_tpl
            typedef gia::gl__type_tpl::binder _name_tpl_binder_t;
            typedef gia::gl__type_tpl::buffer_binder _name_tpl_buffer_binder_t;

            template< typename DataFormat >
            void set__name_tpl(BOOST_PP_ENUM_PARAMS(_size_tpl, DataFormat const _name_tpl_in)) {
              gio::vertexarray_base::bind();
              _name_tpl_binder_t::bind(_location_tpl, BOOST_PP_ENUM_PARAMS(_size_tpl, _name_tpl_in));
            }
            template< typename BufferFormat, typename BufferUsage >
            void set__name_tpl(gio::buffer< BufferFormat, BufferUsage > const& buffer_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const stride_in = 0) {
              gio::vertexarray_base::bind();
              _name_tpl_buffer_binder_t::bind(_location_tpl, buffer_in, offset_in, stride_in);
            }
            template< typename BufferFormat, typename BufferUsage >
            void set__name_tpl_normalized(gio::buffer< BufferFormat, BufferUsage > const & buffer_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const stride_in = 0) {
              gio::vertexarray_base::bind();
              _name_tpl_buffer_binder_t::bind< fc::normalization::normalized >(_location_tpl, buffer_in, offset_in, stride_in);
            }
            template< typename BufferFormat, typename BufferUsage >
            void set__name_tpl_gbra(gio::buffer< BufferFormat, BufferUsage > const & buffer_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const stride_in = 0) {
              gio::vertexarray_base::bind();
              _name_tpl_buffer_binder_t::bind< fc::normalization::none, fc::order::reverse >(_location_tpl,
                  buffer_in,
                  offset_in,
                  stride_in);
            }
            // #template#</attribute>

            // #template#<attribute_array>_name_tpl,_type_tpl,_location_tpl,_size_tpl,_count_tpl
            typedef gia::gl__type_tpl::binder _name_tpl_binder_t;
            typedef gia::gl__type_tpl::buffer_binder _name_tpl_buffer_binder_t;

            template< typename DataFormat >
            void set__name_tpl(DataFormat const values_in[_size_tpl * _count_tpl]) {
              gio::vertexarray_base::bind();
              _name_tpl_binder_t::bind(_location_tpl, _count_tpl, values_in);
            }
            template< typename BufferFormat, typename BufferUsage >
            void set__name_tpl(gio::buffer< BufferFormat, BufferUsage > const & buffer_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const stride_in = 0) {
              gio::vertexarray_base::bind();
              _name_tpl_buffer_binder_t::bind(_location_tpl, buffer_in, offset_in, stride_in);
            }
            template< typename BufferFormat, typename BufferUsage >
            void set__name_tpl_normalized(gio::buffer< BufferFormat, BufferUsage > const& buffer_in,
                ::std::uint32_t const offset_in = 0,
                ::std::uint32_t const stride_in = 0) {
              gio::vertexarray_base::bind();
              _name_tpl_buffer_binder_t::bind< fc::normalization::normalized >(_location_tpl, buffer_in, offset_in, stride_in);
            }
            template< typename BufferFormat, typename BufferUsage >
            void set__name_tpl_gbra(const gio::buffer< BufferFormat, BufferUsage >& buffer_in,
                const ::std::uint32_t offset_in = 0,
                const ::std::uint32_t stride_in = 0) {
              gio::vertexarray_base::bind();
              _name_tpl_buffer_binder_t::bind< fc::normalization::none, fc::order::reverse >(_location_tpl,
                  buffer_in,
                  offset_in,
                  stride_in);
            }
            // #template#</attribute_array>
          };

          typedef gio::vertexarray< vertex_array_format > vertexarray_t;
          ::boost::shared_ptr< vertexarray_t > new_vertexarray() {
            return ::boost::shared_ptr< vertexarray_t >(new vertexarray_t());
          }
        };

      } // namespace program
    } // namespace format

  } // namespace internal
} // namespace gtulu

#endif /* GTULU_PROGRAM_FORMAT_program_upper_tpl_HPP_ */
// #template#</format>

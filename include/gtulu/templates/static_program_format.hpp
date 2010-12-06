// #template#<format>_program_tpl,_author_tpl,_date_tpl
/**
 * @file
 * @date _date_tpl
 */

#ifndef GTULU_PROGRAM_FORMAT_program_upper_tpl_HPP_
#define GTULU_PROGRAM_FORMAT_program_upper_tpl_HPP_

#include <gtulu/opengl.hpp>
#include <gtulu/internal/formats/shader/static.hpp>
#include <gtulu/internal/formats/program/static.hpp>
#include <gtulu/internal/uniform.hpp>
#include <gtulu/internal/attribute.hpp>
#include <gtulu/internal/objects/shader.hpp>
#include <gtulu/internal/objects/program.hpp>
#include <gtulu/internal/objects/vertexarray.hpp>
#include <gtulu/internal/objects/framebuffer.hpp>
#include <gtulu/internal/objects/framebuffer/attacher.hpp>
#include <gtulu/internal/objects/framebuffer/format.hpp>
#include <gtulu/internal/objects/texture.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/preprocessor.hpp>

namespace gtulu {
  namespace internal {

    namespace formats {
      namespace program {

        class _program_tpl_program_format: public fp::static_program_format {
          protected:
            // #template#<define_shader>_shader_tpl,_type_tpl
            class _shader_tpl__type_tpl_shader_format: public fs::static_shader_format< fst::gl__type_tpl > {
              protected:
                static const char* source;

              public:
                _shader_tpl__type_tpl_shader_format() :
                  fs::static_shader_format< fst::gl__type_tpl >() {
                  set_source(get_source());

                  shader_base::compile();
                }

                const char* get_source() const {
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

            void set__name_tpl(BOOST_PP_ENUM_PARAMS(_size_tpl, const _name_tpl_value_t _name_tpl_in)) {
              gio::program_base::bind();
              _name_tpl_binder_t::bind(_location_tpl, BOOST_PP_ENUM_PARAMS(_size_tpl, _name_tpl_in));
            }
            // #template#</uniform>

            // #template#<uniform_sampler>_name_tpl,_type_tpl,_location_tpl
            typedef giu::gl__type_tpl::binder _name_tpl_binder_t;
            typedef giu::gl__type_tpl::value_type _name_tpl_value_t;

            template< typename texture_format_t >
            void set__name_tpl(const gio::texture< texture_format_t >& value_in) {
              gio::program_base::bind();
              _name_tpl_binder_t::bind(_location_tpl, value);
            }
            // #template#</uniform_sampler>

            // #template#<uniform_array>_name_tpl,_type_tpl,_location_tpl,_size_tpl,_count_tpl
            typedef giu::gl__type_tpl::binder _name_tpl_binder_t;
            typedef giu::gl__type_tpl::value_type _name_tpl_value_t;

            void set__name_tpl(const _name_tpl_value_t values_in[_size_tpl * _count_tpl]) {
              gio::program_base::bind();
              _name_tpl_binder_t::bind(_location_tpl, _count_tpl, values_in);
            }
            // #template#</uniform_array>

            template< typename drawable_type_t = const gio::drawable& >
            struct framebuffer_format: public gio::framebuffer_base, public gif::framebuffer_format_base<
                drawable_type_t > {
                // #template#<output>_name_tpl,_type_tpl,_location_tpl,_index_tpl
                template< typename temporary_framebuffer_slot_t = gif::draw_framebuffer_slot,
                    typename new_drawable_type_t >
                void set__name_tpl(const new_drawable_type_t& drawable_in) {
                  gio::framebuffer_base::bind< temporary_framebuffer_slot_t >();
                  gif::framebuffer_format_base< drawable_type_t >::template set<
                      typename temporary_framebuffer_slot_t::slot_type >(_location_tpl, drawable_in);
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
                template< typename drawing_mode_t = gidm::gl_triangles >
                inline void draw(const gio::program< _program_tpl_program_format >& program_in,
                                 const ::boost::uint32_t start_in,
                                 const ::boost::uint32_t count_in,
                                 const ::boost::uint32_t instance_count_in = 1) {
                  draw< drawing_mode_t > (program_in,
                                          *program_in.get_default_framebuffer(),
                                          start_in,
                                          count_in,
                                          instance_count_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles >
                inline void draw_multiple(const gio::program< _program_tpl_program_format >& program_in,
                                          const ::boost::uint32_t starts_in[],
                                          const ::boost::uint32_t counts_in[],
                                          const ::std::size_t count_in) {
                  draw_multiple< drawing_mode_t > (program_in,
                                                   *program_in.get_default_framebuffer(),
                                                   starts_in,
                                                   counts_in,
                                                   count_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles, typename buffer_format_t,
                    typename buffer_usage_t >
                inline void draw(const gio::program< _program_tpl_program_format >& program_in,
                                 const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                 const ::boost::uint32_t count_in,
                                 const ::boost::uint32_t offset_in = 0,
                                 const ::boost::uint32_t instance_count_in = 1,
                                 const ::boost::uint32_t base_vertex_in = 0) {
                  draw< drawing_mode_t > (program_in,
                                          *program_in.get_default_framebuffer(),
                                          buffer_in,
                                          count_in,
                                          offset_in,
                                          instance_count_in,
                                          base_vertex_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles, typename buffer_format_t,
                    typename buffer_usage_t >
                inline void draw_range(const gio::program< _program_tpl_program_format >& program_in,
                                       const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                       const ::boost::uint32_t count_in,
                                       const ::boost::uint32_t min_index_in,
                                       const ::boost::uint32_t max_index_in,
                                       const ::boost::uint32_t offset_in = 0,
                                       const ::boost::uint32_t base_vertex_in = 0) {
                  draw_range< drawing_mode_t > (program_in,
                                                *program_in.get_default_framebuffer(),
                                                buffer_in,
                                                count_in,
                                                min_index_in,
                                                max_index_in,
                                                offset_in,
                                                base_vertex_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles, typename buffer_format_t,
                    typename buffer_usage_t >
                inline void draw_multiple(const gio::program< _program_tpl_program_format >& program_in,
                                          const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                          const ::boost::uint32_t counts_in[],
                                          const ::boost::uint32_t offsets_in[],
                                          const ::std::size_t count_in) {
                  draw_multiple< drawing_mode_t > (program_in,
                                                   *program_in.get_default_framebuffer(),
                                                   buffer_in,
                                                   counts_in,
                                                   offsets_in,
                                                   count_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles >
                inline void draw(const gio::program< _program_tpl_program_format >& program_in,
                                 const gio::framebuffer_base& framebuffer_in,
                                 const ::boost::uint32_t start_in,
                                 const ::boost::uint32_t count_in,
                                 const ::boost::uint32_t instance_count_in = 1) {
                  program_in.bind();
                  framebuffer_in.bind< gif::draw_framebuffer_slot > ();
                  gio::vertexarray_base::bind();
                  gid::drawable::draw< drawing_mode_t >(start_in, count_in, instance_count_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles >
                inline void draw_multiple(const gio::program< _program_tpl_program_format >& program_in,
                                          const gio::framebuffer_base& framebuffer_in,
                                          const ::boost::uint32_t starts_in[],
                                          const ::boost::uint32_t counts_in[],
                                          const ::std::size_t count_in) {
                  program_in.bind();
                  framebuffer_in.bind< gif::draw_framebuffer_slot > ();
                  gio::vertexarray_base::bind();
                  gid::drawable::draw< drawing_mode_t >(starts_in, counts_in, count_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles, typename buffer_format_t,
                    typename buffer_usage_t >
                inline void draw(const gio::program< _program_tpl_program_format >& program_in,
                                 const gio::framebuffer_base& framebuffer_in,
                                 const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                 const ::boost::uint32_t count_in,
                                 const ::boost::uint32_t offset_in = 0,
                                 const ::boost::uint32_t instance_count_in = 1,
                                 const ::boost::uint32_t base_vertex_in = 0) {
                  program_in.bind();
                  framebuffer_in.bind< gif::draw_framebuffer_slot > ();
                  gio::vertexarray_base::bind();
                  gid::drawable::draw< drawing_mode_t >(buffer_in,
                                                        count_in,
                                                        offset_in,
                                                        instance_count_in,
                                                        base_vertex_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles, typename buffer_format_t,
                    typename buffer_usage_t >
                inline void draw_range(const gio::program< _program_tpl_program_format >& program_in,
                                       const gio::framebuffer_base& framebuffer_in,
                                       const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                       const ::boost::uint32_t count_in,
                                       const ::boost::uint32_t min_index_in,
                                       const ::boost::uint32_t max_index_in,
                                       const ::boost::uint32_t offset_in = 0,
                                       const ::boost::uint32_t base_vertex_in = 0) {
                  program_in.bind();
                  framebuffer_in.bind< gif::draw_framebuffer_slot > ();
                  gio::vertexarray_base::bind();
                  gid::drawable::draw< drawing_mode_t >(buffer_in,
                                                        count_in,
                                                        min_index_in,
                                                        max_index_in,
                                                        offset_in,
                                                        base_vertex_in);
                }

                template< typename drawing_mode_t = gidm::gl_triangles, typename buffer_format_t,
                    typename buffer_usage_t >
                inline void draw_multiple(const gio::program< _program_tpl_program_format >& program_in,
                                          const gio::framebuffer_base& framebuffer_in,
                                          const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                          const ::boost::uint32_t counts_in[],
                                          const ::boost::uint32_t offsets_in[],
                                          const ::std::size_t count_in) {
                  program_in.bind();
                  framebuffer_in.bind< gif::draw_framebuffer_slot > ();
                  gio::vertexarray_base::bind();
                  gid::drawable::draw< drawing_mode_t >(buffer_in, counts_in, offsets_in, count_in);
                }

                // #template#<attribute>_name_tpl,_type_tpl,_location_tpl,_size_tpl
                typedef gia::gl__type_tpl::binder _name_tpl_binder_t;
                typedef gia::gl__type_tpl::value_type _name_tpl_value_t;
                typedef gia::gl__type_tpl::buffer_binder _name_tpl_buffer_binder_t;

                void set__name_tpl(BOOST_PP_ENUM_PARAMS(_size_tpl, const _name_tpl_value_t _name_tpl_in)) {
                  gio::vertexarray_base::bind();
                  _name_tpl_binder_t::bind(_location_tpl, BOOST_PP_ENUM_PARAMS(_size_tpl, _name_tpl_in));
                }
                template< typename buffer_format_t, typename buffer_usage_t >
                void set__name_tpl(const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                   const ::boost::uint32_t offset_in = 0,
                                   const ::boost::uint32_t stride_in = 0) {
                  gio::vertexarray_base::bind();
                  _name_tpl_buffer_binder_t::checked_binder< buffer_format_t >::bind(_location_tpl,
                                                                                     buffer_in,
                                                                                     offset_in,
                                                                                     stride_in);
                }
                template< typename buffer_format_t, typename buffer_usage_t >
                void set__name_tpl_normalized(const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                              const ::boost::uint32_t offset_in = 0,
                                              const ::boost::uint32_t stride_in = 0) {
                  gio::vertexarray_base::bind();
                  _name_tpl_buffer_binder_t::checked_binder< buffer_format_t, fdn::normalized >::bind(_location_tpl,
                                                                                                      buffer_in,
                                                                                                      offset_in,
                                                                                                      stride_in);
                }
                template< typename buffer_format_t, typename buffer_usage_t >
                void set__name_tpl_gbra(const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                        const ::boost::uint32_t offset_in = 0,
                                        const ::boost::uint32_t stride_in = 0) {
                  gio::vertexarray_base::bind();
                  _name_tpl_buffer_binder_t::checked_binder< buffer_format_t, fdn::normal, fdo::reverse >::bind(_location_tpl,
                                                                                                                buffer_in,
                                                                                                                offset_in,
                                                                                                                stride_in);
                }
                // #template#</attribute>

                // #template#<attribute_array>_name_tpl,_type_tpl,_location_tpl,_size_tpl,_count_tpl
                typedef gia::gl__type_tpl::binder _name_tpl_binder_t;
                typedef gia::gl__type_tpl::value_type _name_tpl_value_t;
                typedef gia::gl__type_tpl::buffer_binder _name_tpl_buffer_binder_t;

                void set__name_tpl(const _name_tpl_value_t values_in[_size_tpl * _count_tpl]) {
                  gio::vertexarray_base::bind();
                  _name_tpl_binder_t::bind(_location_tpl, _count_tpl, values_in);
                }
                template< typename buffer_format_t, typename buffer_usage_t >
                void set__name_tpl(const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                   const ::boost::uint32_t offset_in = 0,
                                   const ::boost::uint32_t stride_in = 0) {
                  gio::vertexarray_base::bind();
                  _name_tpl_buffer_binder_t::checked_binder< buffer_format_t >::bind(_location_tpl,
                                                                                     buffer_in,
                                                                                     offset_in,
                                                                                     stride_in);
                }
                template< typename buffer_format_t, typename buffer_usage_t >
                void set__name_tpl_normalized(const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                              const ::boost::uint32_t offset_in = 0,
                                              const ::boost::uint32_t stride_in = 0) {
                  gio::vertexarray_base::bind();
                  _name_tpl_buffer_binder_t::checked_binder< buffer_format_t, fdn::normalized >::bind(_location_tpl,
                                                                                                      buffer_in,
                                                                                                      offset_in,
                                                                                                      stride_in);
                }
                template< typename buffer_format_t, typename buffer_usage_t >
                void set__name_tpl_gbra(const gio::buffer< buffer_format_t, buffer_usage_t >& buffer_in,
                                        const ::boost::uint32_t offset_in = 0,
                                        const ::boost::uint32_t stride_in = 0) {
                  gio::vertexarray_base::bind();
                  _name_tpl_buffer_binder_t::checked_binder< buffer_format_t, fdn::normal, fdo::reverse >::bind(_location_tpl,
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
    } // namespace formats

  } // namespace internal
} // namespace gtulu

#endif /* GTULU_PROGRAM_FORMAT_program_upper_tpl_HPP_ */
// #template#</format>

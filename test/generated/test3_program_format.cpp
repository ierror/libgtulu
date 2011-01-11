
/**
 * @file
 */

#include "test3_program_format.hpp"

namespace gtulu {
  namespace internal {
    namespace formats {
      namespace program {

        // #template#<declare_shader_source/>

        char const* test3_program_format::test3_fragment_shader_shader_format::source = "#version 330 core\n"
"in vec3 vertex_color;\n"
"out vec4 color;\n"
"void main() {\n"
"//  color.rgb = vertex_color.rgb;\n"
"  color.rg = gl_FragCoord.rg;\n"
"}\n"
;
        

        char const* test3_program_format::test3_vertex_shader_shader_format::source = "#version 330 core\n"
"in vec2 position;\n"
"in vec3 color;\n"
"out vec3 vertex_color;\n"
"void main() {\n"
"  gl_Position = vec4(position, 0.0, 1.0);\n"
"  vertex_color = color;\n"
"}\n"
;
        
        ;

      } // namespace program
    } // namespace formats
  } // namespace internal
} // namespace gtulu


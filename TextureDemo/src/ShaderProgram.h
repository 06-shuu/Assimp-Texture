//-----------------------------------------------------------------------------
// ShaderProgram.h 
// GLSL shader manager class
//-----------------------------------------------------------------------------
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <map>
#define GLEW_STATIC
#include "GL/glew.h"
#include "glm/glm.hpp"
using std::string;

class ShaderProgram
{
public:
	 ShaderProgram();
	~ShaderProgram();

	enum ShaderType
	{
		VERTEX,
		FRAGMENT,
		PROGRAM
	};

	// Only supports vertex and fragment (this series will only have those two)
	bool loadShaders(const char* vsFilename, const char* fsFilename);
	void use();

	GLuint getProgram() const;

	void setUniform(const GLchar* name, const glm::vec2& v);
	void setUniform(const GLchar* name, const glm::vec3& v);
	void setUniform(const GLchar* name, const glm::vec4& v);
	void setUniform(const GLchar* name, const glm::mat4& m);
	void setUniform(const GLchar* name, const GLfloat f);
	void setUniform(const GLchar* name, const GLint v);
	void setUniformSampler(const GLchar* name, const GLuint textureID);
	void setUniform(GLuint shaderProgramID, const char* uniformName); //added 
	void setInt(const std::string& name, int value) const; //added for the mesh
	void setBool(const std::string& name, bool value) const;
	void setFloat(const std::string& name, float value) const;

private:

	string fileToString(const string& filename);
	void  checkCompileErrors(GLuint shader, ShaderType type);
	// We are going to speed up looking for uniforms by keeping their locations in a map
	GLint getUniformLocation(const GLchar * name);
	
	GLuint mHandle;
	std::map<string, GLint> mUniformLocations;
};
#endif // SHADER_H
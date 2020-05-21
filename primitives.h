#pragma once
#include <glew.h>
#include <glfw3.h>
#include <vector>
#include "Vertex.h"


class Primitive
{
private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

public:
	Primitive() {}
	virtual ~Primitive() {}






	//funkcje 
	void set(const Vertex* vertices,
		const unsigned nrofvert,
		const GLuint* indicies,
		const unsigned nrofindi) {
		for (size_t i = 0; i < nrofvert; i++) {
			this->vertices.push_back(vertices[i]);
			}
		for (size_t i = 0; i < nrofindi; i++) {
			this->indices.push_back(indicies[i]);
		}


	}


	inline Vertex* getVertices() { return this->vertices.data(); }
	inline GLuint* getIndices() { return this->indices.data(); }
	inline const unsigned getNrOfVertices() { return this->vertices.size(); }
	inline const unsigned getNrOfIndices() { return this->indices.size(); }



};


class Quad : public Primitive 
{
public:
	Quad() 
		: Primitive()
	{
		Vertex vertices[] =
		{
			glm::vec3(-0.5f, 0.5f, 0.f), glm::vec3(1.0f, 0.f, 0.f), glm::vec2(0.f, 1.f),glm::vec3(0.0f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.f), glm::vec3(0.0f, 1.f, 0.f), glm::vec2(0.f, 0.f),glm::vec3(0.0f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.f), glm::vec3(0.0f, 0.f, 1.f), glm::vec2(1.f, 0.f),glm::vec3(0.0f, 0.f, 1.f),
			glm::vec3(0.5f, 0.5f, 0.f), glm::vec3(1.0f, 1.f, 0.f), glm::vec2(1.f, 1.f),	glm::vec3(0.0f, 0.f, 1.f)

		};
		unsigned nrOfVerticles = sizeof(vertices) / sizeof(Vertex);
		GLuint indicies[] = {
			0,1,2, //triangle 1 
			0,2,3// triangle 2 

		};
		unsigned nrOfIndices = sizeof(indicies) / sizeof(GLuint);
		this->set(vertices, nrOfVerticles , indicies , nrOfIndices);
	}


};






class Triangle : public Primitive
{
public:
	Triangle()
		: Primitive()
	{
		Vertex vertices[] =
		{
			glm::vec3(-0.5f, 0.5f, 0.f), glm::vec3(1.0f, 0.f, 0.f), glm::vec2(0.f, 1.f),glm::vec3(0.0f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.f), glm::vec3(0.0f, 1.f, 0.f), glm::vec2(0.f, 0.f),glm::vec3(0.0f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.f), glm::vec3(0.0f, 0.f, 1.f), glm::vec2(1.f, 0.f),glm::vec3(0.0f, 0.f, 1.f),
			glm::vec3(0.5f, 0.5f, 0.f), glm::vec3(1.0f, 1.f, 0.f), glm::vec2(1.f, 1.f),	glm::vec3(0.0f, 0.f, 1.f)

		};
		unsigned nrOfVerticles = sizeof(vertices) / sizeof(Vertex);
		GLuint indicies[] = {
			0,1,2 //triangle 1 
			

		};
		unsigned nrOfIndices = sizeof(indicies) / sizeof(GLuint);
		this->set(vertices, nrOfVerticles, indicies, nrOfIndices);
	}


};




class Pyramid : public Primitive
{
public:
	Pyramid()
		: Primitive()
	{
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			//Triangle front
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//Triangle left
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(-1.f, 0.f, 0.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f),

			//Triangle back
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),

			//Triangles right
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(1.f, 0.f, 0.f),
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		this->set(vertices, nrOfVertices, nullptr, 0);
	}
};


class Cube : public Primitive
{
public:
	Cube()
		: Primitive()
	{
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			glm::vec3(-0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			0, 1, 2,
			0, 2, 3,

			7, 6, 1,
			7, 1, 0,

			4, 5, 6,
			4, 6, 7,

			3, 2, 5,
			3, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};
#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

int main() {

	if (!glfwInit()) {

		perror("GLFW init failed.");
		return EXIT_FAILURE;

	}


	// OpenGL v3.3, but I'll still use the ***compatibility*** profile:
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Can't be a `GLFWwindow const*` since `glfw*()` functions prefer `GLFWwindow*`s.
	GLFWwindow *window = glfwCreateWindow(640, 360, "App", NULL, NULL);

	if (!window) {

		glfwTerminate();
		perror("`glfwCreateWindow()` failed");
		return EXIT_SUCCESS;

	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		glRotatef(1, 0, 0, 1);

		glBegin(GL_TRIANGLES);
			glVertex2f(-0.35f, -0.5f); // Left,
			glVertex2f(0.35f, -0.5f);  // Right,
			glVertex2f(0.0f, 0.15f);   // Top.
		glEnd();

		glfwSwapBuffers(window);

		glfwPollEvents();

	}

	glfwDestroyWindow(window);

	glfwTerminate();

	return EXIT_SUCCESS;
}

namespace Core {
template <typename T>
UniformBuffer<T>::UniformBuffer(const Program &program, const std::string &name,
                                int binding) {
    GLint uniformBlockIndex =
        glGetUniformBlockIndex(program.GetId(), name.c_str());
    glUniformBlockBinding(program.GetId(), uniformBlockIndex, binding);

    glGenBuffers(1, &m_BufferId);
    glBindBuffer(GL_UNIFORM_BUFFER, m_BufferId);
    glBufferData(GL_UNIFORM_BUFFER, static_cast<GLsizeiptr>(sizeof(T)), nullptr,
                 GL_DYNAMIC_DRAW);

    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    glBindBufferBase(GL_UNIFORM_BUFFER, binding, m_BufferId);
}

template <typename T>
UniformBuffer<T>::~UniformBuffer() {
    glDeleteBuffers(1, &m_BufferId);
}

template <typename T>
void UniformBuffer<T>::SetData(int offset, const T &data) {
    glBindBuffer(GL_UNIFORM_BUFFER, m_BufferId);
    glBufferSubData(GL_UNIFORM_BUFFER, offset,
                    static_cast<GLsizeiptr>(sizeof(T)), &data);
}
} // namespace Core

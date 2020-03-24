#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <optional>
#include <sstream>

class Error {
public:
    Error() = default;

    Error(std::string error) : error_(std::move(error))
    {}

    Error(const Error&) = default;
    Error& operator=(const Error&) = default;

    Error(Error&&) = default;
    Error& operator=(Error&&) = default;

    explicit operator bool() const {
        return error_.has_value();
    }

    const std::string& GetError() const {
        if (!error_.has_value()) {
            throw std::runtime_error("no error");
        }
        return *error_;
    }

private:
    std::optional<std::string> error_;
};

template <typename T>
class ErrorOr {
public:
    ErrorOr(T t) : t_(std::move(t))
    {}

    ErrorOr(Error error) : error_(std::move(error))
    {}

    ErrorOr(const ErrorOr&) = default;
    ErrorOr& operator=(const ErrorOr&) = default;

    ErrorOr(ErrorOr&&) = default;
    ErrorOr& operator=(ErrorOr&&) = default;

    T ValueOrThrow() const {
        if (error_) {
            throw std::runtime_error("can't get value when an error inside: " + GetError());
        }
        return std::move(t_);
    }

    explicit operator bool() const {
        return static_cast<bool>(error_);
    }

    auto GetError() const {
        return error_.GetError();
    }

    template <typename U>
    Error AssignTo(U& value) {
        if (error_) {
            return error_;
        }
        value = std::move(static_cast<U>(t_));
        return {};
    }

private:
    T t_;
    Error error_;
};

template <typename T>
Error MakeError(T&& error_data) {
    return Error(std::forward<T>(error_data));
}

#define VERIFY(EXP, ERROR)          \
    if (!(EXP)) {                   \
        std::stringstream ss;       \
        ss << ERROR;                \
        return MakeError(ss.str()); \
    }

#define PROPAGATE_ERROR(EXP) \
    if ((EXP)) {             \
        return EXP;          \
    }

#endif // ERROR_H

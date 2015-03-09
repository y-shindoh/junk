#! /usr/bin/ruby -Ku
# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH

class MyStack
    def initialize
        @deque = Array::new
    end

    def empty?
        return @deque.empty?
    end

    def push(value)
        @deque << value
    end

    def reverse
        unless empty? then
            value = @deque.shift
            reverse
            @deque << value
        end
    end

    def pop
        reverse
        value = @deque.shift
        reverse
        return value
    end

    def print(io=$stdout)
        io.puts(@deque.to_s)
    end
end

deque = MyStack::new

STDIN.each { |value|
    value.strip!
    break if value.empty?

    case value
    when 'pop' then
        value = deque.pop
        printf("pop:\t%s\n", value)
    else
        printf("push:\t%s\n", value)
        deque.push(value)
    end

    print("print:\t")
    deque.print
}

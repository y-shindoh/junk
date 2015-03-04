#! /usr/bin/ruby -Ku
# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH

class MyDeque
    def initialize
        @stack = Array::new
    end

    def empty?
        return @stack.empty?
    end

    def enqueue(value)
        @stack << value
    end

    def dequeue
        last = @stack.pop
        if empty? then
            return last
        else
            first = dequeue
            @stack << last
            return first
        end
    end

    def print(io=$stdout)
        io.puts(@stack.to_s)
    end
end

deque = MyDeque::new

STDIN.each { |value|
    value.strip!
    break if value.empty?

    case value
    when 'dequeue' then
        value = deque.dequeue
        printf("dequeue:\t%s\n", value)
    else
        printf("enqueue:\t%s\n", value)
        deque.enqueue(value)
    end

    print("print:\t")
    deque.print
}
